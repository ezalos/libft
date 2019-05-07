/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:01:34 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 12:05:17 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** set : 		lin = 3;
** increment :	lin += 4;
*/

/*
** ft_tabiter(t_tab *tab, size_t dir_one,
** 	int (*f)(t_tab *, size_t, int), size_t dir_two)
*/

void	ft_tabiter(t_tab *t, size_t d,
	int (*f)(t_tab *, size_t, int), size_t s)
{
	t_tab	*ptr;
	int		lin;

	if (t != NULL && f != NULL)
	{
		ptr = t;
		lin = 0;
		while (ptr->dir[d] != NULL)
		{
			f(ptr, s, lin);
			ptr = ptr->dir[d];
			lin++;
		}
		f(ptr, s, lin);
	}
}
