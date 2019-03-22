/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabloop_lendir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:01:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/22 18:44:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_tabloop_lendir(t_tab *tab, size_t dir)
{
	t_tab	*tmp;
	size_t	i;

	if (!tab || dir > 3)
		return (0);
	tmp = tab;
	i = 1;
	while (tmp->dir[dir] && (tmp->dir[dir] != tab))
	{
		tmp = tmp->dir[dir];
		i++;
	}
	return (i);
}
