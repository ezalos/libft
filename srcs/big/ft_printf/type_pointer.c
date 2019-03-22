/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:54:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 12:24:46 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_pointer(t_printf *print, void *ptr)
{
	char		*tmp1;
	char		*tmp2;

	if (!(tmp1 = ft_nb_to_a((intmax_t)ptr, 16)))
		return (-1);
	if (!(tmp2 = ft_strjoin("0x", tmp1)))
		return (-1);
	ft_strdel(&tmp1);
	type_p(&tmp2, print);
	get_printf(print, &tmp2, ft_strlen(tmp2));
	return (0);
}
