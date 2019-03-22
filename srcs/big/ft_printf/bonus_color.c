/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:21:53 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 16:28:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		color_reset(t_printf *print, const char **f, char *str)
{
	if (!(str = ft_strdup("\x1b[0m")))
		return (-1);
	(*f)++;
	if (!get_printf(print, &str, ft_strlen(str)))
		return (-1);
	return (0);
}

int		color_get_rgb(t_printf *print, const char **f, char *str)
{
	get_value_of_star_or_nb(print, f, &print->bonus->red);
	while (**f != ';')
		(*f)++;
	(*f)++;
	get_value_of_star_or_nb(print, f, &print->bonus->green);
	while (**f != ';')
		(*f)++;
	(*f)++;
	get_value_of_star_or_nb(print, f, &print->bonus->blue);
	while (**f != '}')
		(*f)++;
	(*f)++;
	if (!(str = ft_str_rgbcolor(print->bonus->background, print->bonus->red,
		print->bonus->green, print->bonus->blue)))
		return (-1);
	if (!get_printf(print, &str, ft_strlen(str)))
		return (-1);
	return (0);
}

int		color_nb_with_prand_color(t_printf *print, const char **f, char *str)
{
	long long	color_me;

	color_me = va_arg(print->ap, long long);
	print->bonus->red = ft_random(0, 255, (color_me * 3) + 1, 25);
	print->bonus->green = ft_random(0, 255, (color_me * 5) + 1, 2);
	print->bonus->blue = ft_random(0, 255, (color_me * 7) + 1, 5);
	if (!(str = ft_str_rgbcolor(print->bonus->background, print->bonus->red,
		print->bonus->green, print->bonus->blue)))
		return (-1);
	(*f)++;
	(*f)++;
	if (!get_printf(print, &str, ft_strlen(str)))
		return (-1);
	print_integer(print, color_me);
	if (!(str = ft_strdup("\x1b[0m")))
		return (-1);
	if (!get_printf(print, &str, ft_strlen(str)))
		return (-1);
	return (1);
}

int		color_rand_color_based_int_str(t_printf *print, const char **f,
	char *str)
{
	(*f)++;
	if (**f == '}')
	{
		print->bonus->red = ft_random(0, 255, 0, 0);
		print->bonus->green = ft_random(0, 255, 0, 0);
		print->bonus->blue = ft_random(0, 255, 0, 0);
	}
	else
	{
		get_value_of_star_or_nb(print, f, &print->bonus->rand_nb);
		if (!print->bonus->rand_nb)
			print->bonus->rand_nb++;
		print->bonus->red = ft_random(0, 255, (print->bonus->rand_nb * 3), 25);
		print->bonus->green = ft_random(0, 255, (print->bonus->rand_nb * 5), 2);
		print->bonus->blue = ft_random(0, 255, (print->bonus->rand_nb * 7), 5);
	}
	if (!(str = ft_str_rgbcolor(print->bonus->background, print->bonus->red,
		print->bonus->green, print->bonus->blue)))
		return (-1);
	(*f)++;
	if (!get_printf(print, &str, ft_strlen(str)))
		return (-1);
	return (1);
}

int		color_gestion(t_printf *print, const char **f)
{
	char	*str;

	str = NULL;
	(*f)++;
	if (**f == 'b')
	{
		print->bonus->background = 1;
		(*f)++;
	}
	if (**f == '}')
		return (color_reset(print, f, str));
	if (**f == '!')
		return (color_nb_with_prand_color(print, f, str));
	else if (**f == '?')
		return (color_rand_color_based_int_str(print, f, str));
	else
		return (color_get_rgb(print, f, str));
	return (0);
}
