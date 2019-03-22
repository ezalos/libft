/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_lendir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:04:25 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/18 13:45:21 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_tab_lendir(t_tab *tab, size_t dir)
{
	t_tab	*tmp;
	size_t	i;

	if (!tab || dir > 3)
		return (0);
	tmp = tab;
	i = 1;
	while (tmp->dir[dir])
	{
		tmp = tmp->dir[dir];
		i++;
	}
	return (i);
}
