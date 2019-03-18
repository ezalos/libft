/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:33:22 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/18 19:04:49 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabadd_end(t_tab *alst, t_tab *new, size_t dir)
{
	size_t		loop1;
	size_t		loop2;

	if (alst && new)
	{
		if ((loop1 = ft_tabloop_itis(alst, dir)))
			ft_tab_cut_loop(alst, dir);
		if ((loop2 = ft_tabloop_itis(new, dir)))
			ft_tab_cut_loop(new, dir);
		ft_tab_connect_structs(ft_tab_reach_end(alst, dir), new, dir);
		if (loop1)
			ft_tabloop_it(alst, dir);
	}
}
