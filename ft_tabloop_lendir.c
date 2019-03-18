/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabloop_lendir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:01:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/18 13:46:58 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_tabloop_lendir(t_tab *tab, size_t dir)
{
	t_tab	*tmp;
	size_t	i;

//	ft_putstr_color("loop\n", -1, -1, -1);
	if (!tab || dir > 3)
		return (0);
//	ft_putstr_color("1loop\n", -1, -1, -1);
	tmp = tab;
	i = 1;
	while (tmp->dir[dir] && (tmp->dir[dir] != tab))
	{
//		ft_print_address_color((intmax_t)tmp);
//		ft_print_address_color((intmax_t)tab);
//		ft_print_address_color((intmax_t)tab->dir[dir]);
//		ft_putendl("");
		tmp = tmp->dir[dir];
		i++;
	}
//	ft_putstr_color("end loop\n", -1, -1, -1);
	return (i);
}
