/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cutone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:45:14 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/05 17:45:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*ft_tab_cutone(t_tab *to_cut)
{
	size_t dir;

	dir = 0;
	if (!to_cut)
		return (NULL);
	if (to_cut->dir[ft_tab_dir_reverse(dir)] && to_cut->dir[dir])
		ft_tab_connect_structs(to_cut->dir[ft_tab_dir_reverse(dir)], to_cut->dir[dir], dir);
	dir = ft_tab_dir_clock(dir);
	if (to_cut->dir[ft_tab_dir_reverse(dir)] && to_cut->dir[dir])
		ft_tab_connect_structs(to_cut->dir[ft_tab_dir_reverse(dir)], to_cut->dir[dir], dir);
	ft_bzero(to_cut->dir, sizeof(to_cut->dir));
	return (to_cut);
}
