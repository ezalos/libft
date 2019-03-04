/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:33:22 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 20:33:47 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabadd_end(t_tab *alst, t_tab *new, size_t dir)
{
	if (alst && new)
	{
		ft_tab_reach_end(alst, dir)->dir[dir] = new;
		new->dir[ft_tab_dir_reverse(dir)] = alst;
	}
}
