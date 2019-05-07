/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:10:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 18:44:28 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		if (NREE)
		{
			ft_free_with_nalloc(*ap - 8);
			*ap = NULL;
		}
		else
		{
			free(*ap);
			*ap = NULL;
		}
	}
}
