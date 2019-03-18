/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:21:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/15 14:28:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_list	*ft_nalloc_lstnew_ptr(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	{
		new->content_size = content_size;
		new->content = (void*)content;
	}
	new->next = NULL;
	return (new);
}

void			*cnalloc(const void *content, size_t size_content)
{
	void	*new_malloc;
	t_list	*garbage;

	if (!size_content)
		return (NULL);
	if (!*ft_garbage_collector()
	&& !((*ft_garbage_collector()) = ft_nalloc_lstnew_ptr(NULL, 0)))
		ft_burn_garbage(NULL);
	if (!(new_malloc = malloc(size_content)))
		ft_burn_garbage(NULL);
	if (!content)
		ft_bzero(new_malloc, size_content);
	else
		ft_memmove(new_malloc, content, size_content);
	if (!(garbage = ft_nalloc_lstnew_ptr(new_malloc, sizeof(*new_malloc))))
	{
		ft_memdel((void**)&new_malloc);
		ft_burn_garbage(NULL);
	}
	ft_lstadd_end(*ft_garbage_collector(), garbage);
	return (new_malloc);
}
