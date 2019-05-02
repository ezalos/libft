/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd_here.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:32:58 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/01 19:31:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabadd_here(t_tab *alst, t_tab *new, size_t dir)
{
	t_tab		*tmp;
	size_t		loop1;
	size_t		loop2;

	if (alst && new)
	{
		if ((loop1 = ft_tabloop_itis(alst, dir)))
			ft_tab_cut_loop(alst, dir);
		if ((loop2 = ft_tabloop_itis(new, dir)))
			ft_tab_cut_loop(new, dir);
		if (!alst->dir[dir])
			ft_tab_connect_structs(alst, new, dir);
		else
		{
			tmp = alst->dir[dir];
			alst->dir[dir] = new;
			ft_tab_reach_end(new, dir)->dir[dir] = tmp;
			tmp->dir[ft_tab_dir_reverse(dir)] = new;
			new->dir[ft_tab_dir_reverse(dir)] = alst;
		}
		if (loop1)
			ft_tabloop_it(alst, dir);
	}
}
