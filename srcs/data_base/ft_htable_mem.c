/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htable_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:08:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/08 17:08:55 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	**ft_htable_mem(void)
{
	static size_t		*h_table;

	if (!h_table)
		h_table = ft_memalloc(sizeof(*h_table) * SIZE_HTABLE);
	return ((size_t**)&h_table);
}
