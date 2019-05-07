/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_print_one_elmnt.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:58:05 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 12:05:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_print_one_elmnt(t_tab *tmp, size_t lin,
	size_t col, int structh)
{
	size_t				addr;

	addr = 14;
	ft_place_cursor(lin, col);
	ft_putnbr(structh);
	ft_place_cursor(lin, col + addr);
	ft_print_address_color((intmax_t)tmp->dir[0]);
	ft_place_cursor(lin + 1, col);
	ft_print_address_color((intmax_t)tmp->dir[3]);
	ft_print_address_color((intmax_t)tmp);
	ft_print_address_color((intmax_t)tmp->dir[1]);
	ft_place_cursor(lin + 2, col + addr);
	ft_print_address_color((intmax_t)tmp->dir[2]);
	return (0);
}
