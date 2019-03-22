/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_square_it.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:12:01 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/22 18:43:50 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*ft_tab_square_it(t_tab *tab, size_t dir)
{
	t_tab		*tmp;
	t_tab		*tmp_old;
	size_t		len;
	size_t		perp_dir;

	if (!tab || dir > 3)
		return (NULL);
	tmp = tab;
	tmp_old = NULL;
	len = ft_tab_lendir(tab, dir);
	perp_dir = ft_tab_dir_rclock(dir);
	while (tmp && len > 1)
	{
		tmp->dir[perp_dir] = ft_tabnew_dir(len - 1, perp_dir);
		tmp->dir[perp_dir]->dir[ft_tab_dir_reverse(perp_dir)] = tmp;
		if (tmp_old && tmp)
			ft_tab_connect_dir(perp_dir, tmp_old, tmp, dir);
		tmp_old = tmp;
		tmp = tmp->dir[dir];
	}
	return (tab);
}
