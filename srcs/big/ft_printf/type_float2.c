/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:20:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/20 15:23:17 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_int_from_float(intmax_t ldb, char neg)
{
	char			*int_part;
	char			*tmp;

	if (!(int_part = ft_nb_to_a(ldb, 10)))
		return (NULL);
	tmp = int_part;
	if (neg)
	{
		int_part = ft_strjoin("-", tmp);
		ft_strdel(&tmp);
	}
	return (int_part);
}

char		*get_decimal_from_float(t_arg *arg, long double ldb)
{
	char			*decimal_part;
	int				precision;
	int				i;

	if (arg->precision_exist)
		precision = arg->precision;
	else
		precision = 6;
	arg->precision = precision;
	if (!(decimal_part = ft_strnew((size_t)precision + 1 + 1)))
		return (NULL);
	decimal_part[0] = '.';
	i = 0;
	while (++i <= precision + 1)
	{
		ldb = ldb * 10;
		if (((intmax_t)ldb % 10) >= 0 && ((intmax_t)ldb % 10) <= 9)
			decimal_part[i] = ((intmax_t)ldb % 10) + '0';
		else
			decimal_part[i] = '0';
		ldb -= (intmax_t)ldb;
	}
	return (decimal_part);
}

char		*round_move_nb(char *str, size_t len)
{
	int				i;

	i = 0;
	str[i] = '1';
	while (++i <= (int)len)
	{
		if (str[i] == '.')
		{
			str[i] = '0';
			str[i + 1] = '.';
			return (str);
		}
		else
			str[i] = '0';
	}
	return (str);
}
