/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:32:24 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/18 14:20:42 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_tabadd_start(t_tab **alst, t_tab *new, size_t dir)
{
	size_t	len;
	t_tab	*tmp;
	size_t		loop1;
	size_t		loop2;

	ft_putendl(__func__);
	if (alst && new)
	{
		if (*alst)
		{
			if (loop1 = ft_tabloop_itis(*alst, dir))
				ft_tab_cut_loop(*alst, dir);
			if (loop2 = ft_tabloop_itis(new, dir))
				ft_tab_cut_loop(new, dir);
			printf("%p\n", alst);
			len = ft_tabloop_lendir(new, dir);
			printf("len new: %zu\n", len);
			len = ft_tabloop_lendir(*alst, dir);
			printf("len alst: %zu\n", len);
			//tmp = ft_tab_dirth(new, dir, len)->dir[dir];
			//printf("%p\n", tmp);
			//ft_tab_dirth(new, dir, len)->dir[dir] = *alst;
			//ft_tab_reach_end(new, dir)->dir[dir] = *alst;
			new->dir[dir] = *alst;
			new->dir[ft_tab_dir_reverse(dir)] = NULL;
			(*alst)->dir[ft_tab_dir_reverse(dir)] = new;
			*alst = new;
			len = ft_tabloop_lendir(*alst, dir);
			printf("len alst: %zu\n", len);

			if (loop1)
				ft_tabloop_it(*alst, dir);
			if (loop2)
				ft_tabloop_it(new, dir);
		}
		else
			*alst = new;
	}
}
