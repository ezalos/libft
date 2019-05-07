/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:21:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 15:10:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*cnalloc(const void *content, size_t size_content)
{
	void	*new_malloc;

	if (!size_content)
		return (NULL);
	new_malloc = nalloc(size_content);
	if (!content)
		ft_bzero(new_malloc, size_content);
	else
		ft_memmove(new_malloc, content, size_content);
	return (new_malloc);
}
