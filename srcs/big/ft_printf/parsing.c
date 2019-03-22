/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:35:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/20 20:01:15 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parsing_integer(t_printf *print)
{
	if (print->arg->modifier_l == 1)
		print_integer(print, va_arg(print->ap, long));
	else if (print->arg->modifier_l == 2)
		print_integer(print, va_arg(print->ap, long long));
	else if (print->arg->modifier_h == 1)
		print_integer(print, (short int)va_arg(print->ap, int));
	else if (print->arg->modifier_h == 2)
		print_integer(print, (char)va_arg(print->ap, int));
	else
		print_integer(print, (int)va_arg(print->ap, int));
	return (0);
}

int			parsing_unsigned_integer(t_printf *print)
{
	if (print->arg->modifier_l == 1)
		print_unsigned_integer(print, va_arg(print->ap, unsigned long));
	else if (print->arg->modifier_l == 2)
		print_unsigned_integer(print, va_arg(print->ap, unsigned long long));
	else if (print->arg->modifier_h == 1)
		print_unsigned_integer(print,
		(unsigned short int)va_arg(print->ap, unsigned int));
	else if (print->arg->modifier_h == 2)
		print_unsigned_integer(print,
		(unsigned char)va_arg(print->ap, unsigned int));
	else
		print_unsigned_integer(print,
		(unsigned int)va_arg(print->ap, unsigned int));
	return (0);
}

int			parsing_float(t_printf *print)
{
	if (print->arg->type == 'f')
		print_float(print, va_arg(print->ap, double));
	return (0);
}

int			parsing(t_printf *print)
{
	if (ft_char_srch(print->arg->type, "di"))
		parsing_integer(print);
	else if (ft_char_srch(print->arg->type, "ouxX"))
		parsing_unsigned_integer(print);
	else if (ft_char_srch(print->arg->type, "feEgG"))
		parsing_float(print);
	else if (print->arg->type == 's')
		print_string(print, va_arg(print->ap, char*));
	else if (print->arg->type == 'c')
		print_character(print, (char)va_arg(print->ap, int));
	else if (print->arg->type == 'p')
		print_pointer(print, va_arg(print->ap, void*));
	else if (print->arg->type == 'b')
		print_binary(print, va_arg(print->ap, void*));
	else
	{
		print->format++;
		print_character(print, print->arg->type);
	}
	return (0);
}
