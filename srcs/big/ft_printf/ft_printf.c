/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 18:46:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			paste_format_in_printf(t_printf *print)
{
	char			*tmp;
	char			*tmp2;

	if (print->i <= 0)
		return (1);
	if (!(tmp = ft_strsub(print->format, 0, (size_t)print->i)))
		return (0);
	tmp2 = print->printf;
	if (tmp2)
	{
		if (!(print->printf = ft_strjoin(tmp2, tmp)))
			return (0);
		ft_strdel(&tmp2);
		ft_strdel(&tmp);
	}
	else
		print->printf = tmp;
	print->format += print->i;
	print->size_all += (size_t)print->i;
	print->i = 0;
	return (1);
}

int			we_just_found_a_percent(t_printf *print)
{
	if (!(paste_format_in_printf(print)))
		return (-1);
	init_struct_arg(print);
	print->format++;
	check_arg(print, &print->format);
	if (print->arg->type != '\0')
		parsing(print);
	return (0);
}

int			ft_printf(const char *format, ...)
{
	t_printf			print;
	int					r_val;

	if (!(init_struct(&print, format)))
		return (-1);
	va_start(print.ap, format);
	print.i = 0;
	while (print.format[print.i])
	{
		if (ft_char_srch(print.format[print.i], "%"))
			we_just_found_a_percent(&print);
		if (print.format[print.i] != '%' && print.format[print.i])
			print.i++;
	}
	if (!(paste_format_in_printf(&print)))
		return (-1);
	output_string(&print);
	r_val = (int)print.size_all;
	return (r_val);
}
