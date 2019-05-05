/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cut_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:07:52 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/03 15:46:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_cut_loop(t_tab *tab, size_t dir)
{
	size_t	len;

	if (!tab)
		return (0);
	len = ft_tabloop_lendir(tab, dir);
	ft_tab_dirth(tab, dir, len - 1)->dir[dir] = NULL;
	tab->dir[ft_tab_dir_reverse(dir)] = NULL;
	return (len - 1);
}
