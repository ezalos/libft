/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:33:54 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/18 14:21:13 by ldevelle         ###   ########.fr       */
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
**	0x0  <-   <---   <---   <---   <---   <---   <---   <---         -dir
**	        X      X      X      X      X      X      X      X
**	          --->   --->   --->   --->   --->   --->   --->  -> 0x0  dir
**		  ^      ^      ^      ^      ^      ^      ^      ^   ^
**	      |      |      |      |      |      |      |      |   |
**	     -3     -2     -1      0      1      2      3      4   5      umpteenth
**
**	If umpteenth is negatif, it reverse the choosen dir.
*/

void		ft_tabadd(t_tab	**tab, t_tab *new, size_t dir, int umpteenth)
{
	t_tab		*tmp;
	size_t		loop1;
	size_t		loop2;

//	ft_putendl(__func__);
	if (tab && *tab && new)
	{
		if (loop1 = ft_tabloop_itis(*tab, dir))
			ft_tab_cut_loop(*tab, dir);
		if (loop2 = ft_tabloop_itis(new, dir))
			ft_tab_cut_loop(new, dir);
//		ft_putendl("1");
		if (!umpteenth)
		{
//			ft_putendl("if");
			ft_tabadd_start(tab, new, dir);
		}
		else
		{
//			ft_putendl("else");
			if (umpteenth < 0)
			{
//				ft_putendl("if");
				dir = ft_tab_dir_reverse(dir);
				umpteenth = -umpteenth;
			}
//			ft_putendl("nop");
			umpteenth--;
			tmp = ft_tab_dirth(*tab,  dir, umpteenth);
//			ft_putendl("bef tab here");
			ft_tabadd_here(tmp, new, dir);
		}
		if (loop1)
			ft_tabloop_it(*tab, dir);
		if (loop2)
			ft_tabloop_it(new, dir);
	}
}
