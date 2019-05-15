/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:18:57 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/15 14:20:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*nalloc(size_t size_content)
{
	char	*new_malloc;

	if (!size_content)
		return (NULL);
	if (!*ft_garbage_collector())
	{
		if (!((*ft_garbage_collector()) = malloc(size_content + sizeof(void*))))
			ft_burn_garbage(NULL);
		ft_bzero((*ft_garbage_collector()), sizeof(void*));
		return ((*ft_garbage_collector()) + sizeof(void*));
	}
	else
	{
		if (!(new_malloc = malloc(size_content + sizeof(void*))))
			ft_burn_garbage(NULL);
		ft_memmove(new_malloc, ft_garbage_collector(), sizeof(void*));
		*ft_garbage_collector() = new_malloc;
	}
	return (new_malloc + sizeof(void*));
}
