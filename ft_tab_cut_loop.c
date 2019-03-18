/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cut_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:07:52 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/18 14:08:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_cut_loop(t_tab *tab, size_t dir)
{
	size_t	len;

	len = ft_tabloop_lendir(tab, 0);
	ft_tab_dirth(tab, 0, len)->dir[dir] = NULL;
	tab->dir[ft_tab_dir_reverse(dir)] = NULL;
	return (len);
}
