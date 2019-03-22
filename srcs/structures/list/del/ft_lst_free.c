/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:22:07 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/14 15:45:24 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_lst_free(t_list **delete_me)
{
	t_list	*tmp;
	t_list	*next;
	t_list	*leaks;
	size_t	i;

	if (!delete_me)
		return (0);
	tmp = *delete_me;
	i = 0;
	while (tmp)
	{
		next = tmp->next;
		leaks = tmp->content;
		ft_strdel((char**)&leaks);
		ft_strdel((char**)&tmp);
		i++;
		tmp = next;
	}
	return (i);
}
