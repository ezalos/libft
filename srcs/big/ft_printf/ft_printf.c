/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/11/03 15:34:15 by gtaja            ###   ########.fr       */
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

	*(switch_garbage()) = TRUE;
	r_val = -1;
	if (init_struct(&print, format))
	{
		va_start(print.ap, format);
		print.i = 0;
		while (print.format[print.i])
		{
			if (ft_char_srch(print.format[print.i], "%"))
				we_just_found_a_percent(&print);
			if (print.format[print.i] != '%' && print.format[print.i])
				print.i++;
		}
		if ((paste_format_in_printf(&print)))
		{
			output_string(&print);
			r_val = (int)print.size_all;
		}
	}
	ft_clean_garbage();
	*(switch_garbage()) = FALSE;
	return (r_val);
}
