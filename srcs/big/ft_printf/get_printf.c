/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:18:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/09 22:39:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_minimum_width_0(t_printf *print)
{
	int		i;

	i = print->arg->minimum_width;
	if (print->arg->minimum_width > 1)
	{
		while (--i > 0)
			write(1, &print->arg->space_filled, 1);
		print->size_all += print->arg->minimum_width - 1;
	}
}

void		write_0(t_printf *print, char **str)
{
	output_string(print);
	if (print->arg->zero_exist)
		print->arg->space_filled = '0';
	if (print->arg->ajust_left)
	{
		write(1, "\0", 1);
		add_minimum_width_0(print);
	}
	else
	{
		add_minimum_width_0(print);
		write(1, "\0", 1);
	}
	ft_strdel(str);
}

int			get_printf(t_printf *print, char **str, size_t content_size)
{
	char	*tmp;

	if (!str || !*str)
		return (1);
	tmp = print->printf;
	print->size_all += content_size;
	if (**str == 0)
	{
		write_0(print, str);
		return (1);
	}
	if (tmp)
	{
		if (!(print->printf = ft_strjoin(tmp, *str)))
			return (0);
		ft_strdel(&tmp);
		ft_strdel(str);
	}
	else
	{
		print->printf = *str;
	}
	return (1);
}
