/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:23:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/16 14:09:38 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstadd(t_list **alst, t_list *new, int position)
{
	t_list		*tmp;

	if (alst != NULL && *alst != NULL && new != NULL)
	{
		if (position < 0)
			ft_lstadd_start(alst, new);
		else
		{
			tmp = ft_find_lsth(*alst, position);
			ft_lstadd_here(tmp, new);
		}
	}
}
