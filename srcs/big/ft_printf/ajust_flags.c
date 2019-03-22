/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ajust_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:45:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/20 19:46:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_oux(t_printf *print, char **str)
{
	if (print->arg->type == 'o' && *str[0] == '0')
		print->arg->htag = 0;
	if (!print->arg->precision_exist && !print->arg->minimum_width)
	{
		if (add_htag(print, str) == -1)
			return (-1);
	}
	else
	{
		if (print->arg->type == 'o' && print->arg->precision_exist
			&& print->arg->htag)
			print->arg->precision--;
		if (print->arg->precision_exist)
			if (add_precison(print, str) == -1)
				return (-1);
		if (add_htag(print, str) == -1)
			return (-1);
		if (add_minimum_width(print, str) == -1)
			return (-1);
		if (print->arg->space_filled == '0' && print->arg->htag
		&& ft_char_srch(print->arg->type, "xX"))
			reajust_hatg(print, *str);
	}
	return (1);
}

int		type_dic(t_printf *print, char **str)
{
	if (print->arg->precision_exist && *str[0] != '%'
	&& print->arg->type != 'c')
		if (add_precison(print, str) == -1)
			return (-1);
	if (print->arg->sign && (print->arg->type == 'd'
	|| print->arg->type == 'i'))
		if (!(add_sign(str)))
			return (-1);
	if (*str[0] == '0' && (print->arg->type == 'd' || print->arg->type == 'i'))
		reajust_sign(*str);
	if (print->arg->type != 'd' && print->arg->type != 'i'
		&& print->arg->zero_exist && !print->arg->ajust_left)
		print->arg->space_filled = '0';
	if (print->arg->space && print->arg->ajust_left)
		print->arg->minimum_width--;
	if (add_minimum_width(print, str) == -1)
		return (-1);
	if (print->arg->space_filled == '0')
		reajust_sign(*str);
	if (print->arg->space && print->arg->type != 'c' && *str[0] != ' '
	&& *str[0] != '-' && ft_char_srch(print->arg->type, "di"))
		if (!(add_space(print, str)))
			return (-1);
	return (1);
}

int		type_empty(t_printf *print, char **str)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = *str;
	if (print->arg->minimum_width)
	{
		if (!(tmp = ft_strnew(print->arg->minimum_width)))
			return (-1);
		ft_memset(tmp, print->arg->space_filled, print->arg->minimum_width);
		*str = tmp;
		ft_strdel(&tmp2);
	}
	return (1);
}

int		type_s(t_printf *print, char **str)
{
	int		len;

	len = ft_strlen(*str);
	if (print->arg->precision < len && print->arg->precision_exist)
		(*str)[print->arg->precision] = '\0';
	if (!**str)
	{
		if (type_empty(print, str) == -1)
			return (-1);
		return (1);
	}
	if (print->arg->zero_exist && !print->arg->ajust_left)
		print->arg->space_filled = '0';
	if (add_minimum_width(print, str) == -1)
		return (-1);
	return (1);
}

int		ajust_flags(t_printf *print, char **str)
{
	if (!print->arg->precision && print->arg->precision_exist && *str[0] == '0')
	{
		if (type_empty(print, str) == -1)
			return (-1);
	}
	else if (ft_char_srch(print->arg->type, "ouxX"))
	{
		if (type_oux(print, str) == -1)
			return (-1);
	}
	else if (print->arg->type == 's')
	{
		if (type_s(print, str) == -1)
			return (-1);
	}
	else
	{
		if (type_dic(print, str) == -1)
			return (-1);
	}
	return (1);
}
