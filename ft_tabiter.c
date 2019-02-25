/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:01:34 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/25 22:01:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabiter(t_tab *tab, size_t dir, int(*f)(t_tab *, size_t, int), size_t dirf)
{
	t_tab	*ptr;
	int 	i;
	int		lin;

	if (tab != NULL && f != NULL)
	{
		ptr = tab;
		lin = 3;
		while (ptr->dir[dir] != NULL)
		{
			i = (*f)(ptr, dirf, lin);
			ptr = ptr->dir[dir];
			lin += 4;
		}
		f(ptr, dirf, lin);
	}
}
