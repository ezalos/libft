/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_connect_structs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:29:22 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 12:20:31 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_tab_connect_structs(t_tab *t_one, t_tab *t_two, size_t dir_one)
{
	size_t	dir_two;

	dir_two = ft_tab_dir_reverse(dir_one);
	t_one->dir[dir_one] = t_two;
	t_two->dir[dir_two] = t_one;
}
