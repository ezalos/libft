/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:54:32 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/20 15:23:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			float_exception(t_printf *print, double ldb)
{
	unsigned char	*conv;
	char			*str;
	int				i;

	conv = (unsigned char*)&ldb;
	i = -1;
	if (ldb < 0 && ldb / 2 == ldb)
		str = ft_strdup("-inf");
	else if (ldb != ldb)
		str = ft_strdup("nan");
	else if (ldb > 0 && ldb / 2 == ldb)
		str = ft_strdup("inf");
	else
		return (0);
	paste_float_in_printf(print, str);
	return (1);
}

char		*round_float_str(char *str)
{
	size_t			len;
	int				i;

	len = ft_strlen(str);
	len--;
	if (str[len] > '5' && ft_isdigit(str[len]))
	{
		i = 0;
		while (++i <= (int)len)
		{
			if (str[len - i] == '9')
				str[len - i] = '0';
			else if (ft_isdigit(str[len - i]))
			{
				str[len - i]++;
				str[len] = 0;
				return (str);
			}
			if (i == (int)len)
				return (round_move_nb(str, len));
		}
	}
	str[len] = 0;
	return (str);
}

void		float_no_htag(t_printf *print, char *int_part, char *decimal_part)
{
	if (ft_strlen(decimal_part) > 3
	|| (!print->arg->precision && print->arg->precision_exist))
	{
		print->last_type = ft_strjoin(int_part, decimal_part);
		print->last_type = round_float_str(print->last_type);
		if (!print->arg->precision && print->arg->precision_exist)
			print->last_type[ft_strlen(print->last_type) - 1] = 0;
	}
	else
	{
		if (print->arg->precision == 1)
		{
			print->last_type = ft_strnew(ft_strlen(int_part) + 2);
			ft_memmove(print->last_type, int_part, ft_strlen(int_part));
			ft_memmove(print->last_type + ft_strlen(int_part), decimal_part, 2);
		}
		else
			print->last_type = ft_strdup(int_part);
	}
}

void		neg_gestion(char *neg, long double *ldb)
{
	*neg = 0;
	if (*ldb < 0)
	{
		*neg = 1;
		*ldb = -*ldb;
	}
}

int			print_float(t_printf *print, long double ldb)
{
	char			neg;
	char			*int_part;
	char			*decimal_part;

	if (print->arg->zero_exist)
		print->arg->space_filled = '0';
	if (float_exception(print, ldb))
		return (0);
	neg_gestion(&neg, &ldb);
	if (!(int_part = get_int_from_float((intmax_t)ldb, neg))
	|| !(decimal_part = get_decimal_from_float(print->arg,
		ldb - (intmax_t)ldb)))
		return (-1);
	if (print->arg->htag)
	{
		print->last_type = ft_strjoin(int_part, decimal_part);
		print->last_type = round_float_str(print->last_type);
	}
	else
		float_no_htag(print, int_part, decimal_part);
	ft_strdel(&int_part);
	ft_strdel(&decimal_part);
	paste_float_in_printf(print, print->last_type);
	return (0);
}
