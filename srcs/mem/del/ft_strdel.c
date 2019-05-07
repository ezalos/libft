/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:18:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 18:44:50 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strdel(char **as)
{
	if (as && *as)
	{
		if (NREE)
		{
			ft_free_with_nalloc(*as - 8);
			*as = NULL;
		}
		else
		{
			free(*as);
			*as = NULL;
		}
	}
}
