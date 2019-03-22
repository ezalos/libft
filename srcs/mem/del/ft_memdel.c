/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:10:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 16:46:49 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstfind_and_free(void **ap)
{
	t_list		*tmp;

	tmp = *ft_garbage_collector();
	while (tmp)
	{
		if (*ap == tmp->content)
		{
			free(tmp->content);
			tmp->content = NULL;
			return ;
		}
		tmp = tmp->next;
	}
}

void		ft_memdel(void **ap)
{
	if (!ap)
		if (!*ap)
		{
			if (NREE)
			{
				ft_lstfind_and_free(ap);
				*ap = NULL;
			}
			else
			{
				free(*ap);
				*ap = NULL;
			}
		}
}
