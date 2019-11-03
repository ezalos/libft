/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:18:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/11/03 07:47:16 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strdel(char **as)
{
	if (as && *as)
	{
		if (*(switch_garbage()))
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
