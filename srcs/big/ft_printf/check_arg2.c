/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:57:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/20 19:48:47 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(const char c, t_arg *arg)
{
	if (c == '0')
	{
		arg->zero_exist = 1;
		if (!arg->ajust_left && !arg->precision_exist)
			arg->space_filled = '0';
	}
	else if (c == '+')
	{
		arg->sign = 1;
		arg->space = 0;
	}
	else if (c == '-')
	{
		arg->ajust_left = 1;
		arg->space_filled = ' ';
	}
	else if (c == '#')
		arg->htag = 1;
	else if (c == ' ' && !arg->sign)
		arg->space = 1;
	if (arg->ajust_left && arg->space_filled == '0')
		arg->space_filled = ' ';
}

int		get_value_of_star_or_nb(t_printf *print, const char **f, int *tmp)
{
	*tmp = 0;
	if (**f == '*')
	{
		if (print->arg->zero_exist)
			print->arg->space_filled = '0';
		*tmp = (int)va_arg(print->ap, int);
		(*f)++;
	}
	else if (ft_isdigit(**f))
		while (ft_isdigit(**f))
			*tmp = *tmp * 10 + *(*f)++ - 48;
	return (*tmp);
}

char	*get_value_of_star_or_str(t_printf *print, const char **f, char **tmp)
{
	size_t		len;

	len = 0;
	if (**f == '*')
	{
		*tmp = va_arg(print->ap, char*);
		(*f)++;
	}
	else
	{
		while ((*f)[len] != '}')
			len++;
		*tmp = ft_memalloc(len + 1);
		ft_memmove(*tmp, (*f), len);
		(*f) += len;
	}
	return (*tmp);
}

void	check_min_or_pre2(t_printf *print, const char **f, int *tmp, int pres)
{
	*tmp = 0;
	get_value_of_star_or_nb(print, f, tmp);
	if (!pres && *tmp < 0)
	{
		*tmp = -*tmp;
		print->arg->ajust_left = 1;
	}
	if (print->arg->precision)
		print->arg->space_filled = ' ';
}

void	check_minimum_width_or_precision(t_printf *print, const char **f)
{
	int		*tmp;
	int		pres;

	pres = 0;
	if (**f == '.')
	{
		tmp = &print->arg->precision;
		print->arg->precision_exist = 1;
		print->arg->space_filled = ' ';
		(*f)++;
		if (**f == '0')
		{
			(*f)++;
			return ;
		}
		pres = 1;
	}
	else
		tmp = &print->arg->minimum_width;
	check_min_or_pre2(print, f, tmp, pres);
}
