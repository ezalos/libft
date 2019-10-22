/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:15:19 by ldevelle          #+#    #+#             */
/*   Updated: 2019/10/22 09:28:20 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_ptr(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = P_MALLOC(sizeof(t_list))))
		return (NULL);
	new->content_size = content_size;
	new->content = (void*)content;
	new->next = NULL;
	return (new);
}
