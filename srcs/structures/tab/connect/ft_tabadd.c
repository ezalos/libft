/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:33:54 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/23 16:41:49 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Insertion of new element will be just before the choosen umpteenth.
**	This way, entering 0 allows to change head of list (when at begining)
**	Insetingan element always link it dir and reverse_dir
**
**	                          **tab
**	                             |
**	                             v
**	0x0  <-   <---   <---   <---   <---   <---   <---   <---          -dir
**	        X      X      X      X      X      X      X      X
**	          --->   --->   --->   --->   --->   --->   --->  -> 0x0   dir
**		  ^      ^      ^      ^      ^      ^      ^      ^   ^
**	      |      |      |      |      |      |      |      |   |
**	     -3     -2     -1      0      1      2      3      4   5      umpteenth
**
**	If umpteenth is negatif, it reverse the choosen dir.
*/

static int	ft_tabadd_else(t_tab **tab, t_tab *new, size_t *dir, int umpteenth)
{
	t_tab		*tmp;

	if (umpteenth < 0)
	{
		*dir = ft_tab_dir_reverse(*dir);
		umpteenth = -umpteenth;
	}
	umpteenth--;
	tmp = ft_tab_dirth(*tab, *dir, umpteenth);
	ft_tabadd_here(tmp, new, *dir);
	return (1);
}

void		ft_tabadd(t_tab **tab, t_tab *new, size_t dir, int umpteenth)
{
	size_t		loop1;
	size_t		loop2;

	if (tab && *tab && new)
	{
		if ((loop1 = ft_tabloop_itis(*tab, dir)))
			ft_tab_cut_loop(*tab, dir);
		if ((loop2 = ft_tabloop_itis(new, dir)))
			ft_tab_cut_loop(new, dir);
		if (!umpteenth)
			ft_tabadd_start(tab, new, dir);
		else
			ft_tabadd_else(tab, new, &dir, umpteenth);
		if (loop1)
			ft_tabloop_it(*tab, dir);
	}
}
