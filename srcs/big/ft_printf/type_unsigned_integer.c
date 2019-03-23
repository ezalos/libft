/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_unsigned_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:52:49 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/23 19:17:21 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_unsigned_integer(t_printf *print, uintmax_t nb)
{
	int		base;
	int		i;

	base = 10;
	if (print->arg->type == 'o')
		base = 8;
	else if (print->arg->type == 'x' || print->arg->type == 'X')
		base = 16;
	print->last_type = ft_u_nb_to_a(nb, base);
	i = -1;
	if (print->arg->type == 'X')
		while (print->last_type[++i])
			print->last_type[i] = ft_toupper(print->last_type[i]);
	if (print->last_type[0] == '0' && (print->arg->type == 'x'
	|| print->arg->type == 'X'))
		print->arg->htag = 0;
	paste_int_in_printf(print, print->last_type);
	return (0);
}
