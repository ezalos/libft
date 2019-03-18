/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cutone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:45:14 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/18 19:01:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*ft_tab_cutone(t_tab *to_cut)
{
	t_tab	*tmp;
	size_t	dir;

	dir = 0;
	if (!to_cut)
		return (NULL);
	tmp = to_cut;
	if (tmp->dir[ft_tab_dir_reverse(dir)] && tmp->dir[dir])
		ft_tab_connect_structs(tmp->dir[ft_tab_dir_reverse(dir)], tmp->dir[dir], dir);
	else if (tmp->dir[ft_tab_dir_reverse(dir)])
		tmp->dir[ft_tab_dir_reverse(dir)]->dir[dir] = NULL;
	else if (tmp->dir[dir])
		tmp->dir[dir]->dir[ft_tab_dir_reverse(dir)] = NULL;
	dir = ft_tab_dir_clock(dir);
	if (tmp->dir[ft_tab_dir_reverse(dir)] && tmp->dir[dir])
		ft_tab_connect_structs(tmp->dir[ft_tab_dir_reverse(dir)], tmp->dir[dir], dir);
	else if (tmp->dir[ft_tab_dir_reverse(dir)])
		tmp->dir[ft_tab_dir_reverse(dir)]->dir[dir] = NULL;
	else if (tmp->dir[dir])
		tmp->dir[dir]->dir[ft_tab_dir_reverse(dir)] = NULL;
	dir = 0;
	while (dir < 4)
		tmp->dir[dir++] = NULL;
	return (tmp);
}
