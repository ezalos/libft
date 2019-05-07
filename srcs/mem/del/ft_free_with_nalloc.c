/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_with_nalloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:44:30 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 19:14:04 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_with_nalloc(void *elem)
{
	void ***it;

	if (!(it = *ft_garbage_collector()))
		return ;
	if (it == elem)
	{
		*ft_garbage_collector() = *(void**)(*ft_garbage_collector());
		free(elem);
		return ;
	}
	while (it)
	{
		if (*it == elem)
		{
			ft_memcpy(it, *it, sizeof(void*));
			free(elem);
		}
		else
			it = (void***)*it;
	}
}
