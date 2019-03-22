/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:32:24 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/22 18:42:50 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabadd_start(t_tab **alst, t_tab *new, size_t dir)
{
	size_t		loop1;
	size_t		loop2;

	if (alst && new)
	{
		if (*alst)
		{
			if ((loop1 = ft_tabloop_itis(*alst, dir)))
				ft_tab_cut_loop(*alst, dir);
			if ((loop2 = ft_tabloop_itis(new, dir)))
				ft_tab_cut_loop(new, dir);
			new->dir[dir] = *alst;
			new->dir[ft_tab_dir_reverse(dir)] = NULL;
			(*alst)->dir[ft_tab_dir_reverse(dir)] = new;
			*alst = new;
			if (loop1)
				ft_tabloop_it(*alst, dir);
		}
		else
			*alst = new;
	}
}
