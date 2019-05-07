/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_garbage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:21:44 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 19:12:15 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_clean_garbage(void)
{
	void **it;
	void **it_next;

	if (!(it = *ft_garbage_collector()))
		return ;
	it_next = *it;
	while (it && *it)
	{
		free(it);
		it = it_next;
		it_next = *it_next;
	}
	free(it);
	*ft_garbage_collector() = NULL;
}
