/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:35:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 17:31:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			paste_int_in_printf(t_printf *print, char *str)
{
	if (print->arg->precision < 0)
	{
		print->arg->precision = 0;
		if (print->arg->zero_exist)
			print->arg->space_filled = '0';
	}
	if (str[0] == '-')
		print->arg->sign = 0;
	if (!print->arg->precision && !print->arg->minimum_width
	&& print->arg->precision_exist && str[0] == '0')
	{
		if (print->arg->htag)
		{
			if (!(get_printf(print, &str, ft_strlen(str))))
				return (-1);
		}
		return (1);
	}
	if (!(ajust_flags(print, &str)))
		return (-1);
	if (!(get_printf(print, &str, ft_strlen(str))))
		return (-1);
	return (1);
}
