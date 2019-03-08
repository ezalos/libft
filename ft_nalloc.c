/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:18:57 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/07 23:58:21 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*nalloc(size_t size_content)
{
	void	*new_malloc;
	t_list	*garbage;

	if (!size_content)
		return (NULL);
	if (!(new_malloc = malloc(size_content)))
		ft_clean_garbage();
	if (!(garbage = ft_lstnew_ptr(new_malloc, sizeof(new_malloc))))
		ft_clean_garbage();
	if (!ft_garbage_collector())
		*ft_garbage_collector() = garbage;
	else
		ft_lstadd_end(*ft_garbage_collector(), garbage);
	return (new_malloc);
}
