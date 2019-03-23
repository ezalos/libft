/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:54:06 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/23 19:24:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_integer(t_printf *print, intmax_t nb)
{
	int	base;

	base = 10;
	print->last_type = ft_nb_to_a(nb, base);
	paste_int_in_printf(print, print->last_type);
	return (0);
}
