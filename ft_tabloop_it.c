/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabloop_it.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:01:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/18 19:08:56 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_tabloop_it(t_tab *tab, size_t dir)
{
	t_tab	*tmp;

	if (ft_tabloop_itis(tab, dir))
		return (0);
	tmp = ft_tab_reach_end(tab, dir);
	ft_tab_connect_structs(tmp, tab, dir);
	return (1);
}
