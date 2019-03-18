/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabloop_itis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:08:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/18 14:10:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_tabloop_itis(t_tab *tab, size_t dir)
{
	t_tab	*tmp;

	if (!tab || dir > 3)
		return (0);
	tmp = tab;
	while (tmp->dir[dir])
	{
		if (tmp->dir[dir] == tab)
			return (1);
		tmp = tmp->dir[dir];
	}
	return (0);
}
