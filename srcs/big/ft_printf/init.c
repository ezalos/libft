/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:01:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 17:20:19 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_struct_arg(t_printf *print)
{
	ft_bzero(print->arg, sizeof(t_arg));
	print->arg->space_filled = ' ';
}

int			init_struct(t_printf *print, const char *format)
{
	ft_bzero(print, sizeof(*print));
	if (print->start_format)
		ft_strdel(&print->start_format);
	if (!(print->format = ft_strdup(format)))
	{
		print->start_format = (char*)print->format;
		return (0);
	}
	print->fd = 1;
	print->invisible = 0;
	return (1);
}
