/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_connect_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:10:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 12:22:31 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** int			ft_tab_connect_dir(size_t dir_line, t_tab *line_one,
** 	t_tab *line_two, size_t dir_connec)
*/

int			ft_tab_connect_dir(size_t d_a, t_tab *l_a, t_tab *l_b, size_t d_b)
{
	t_tab	*tmp_one;
	t_tab	*tmp_two;
	int		already;

	if (!l_a || d_a > 3 || !l_b || d_b > 3)
		return (-1);
	tmp_one = l_a;
	tmp_two = l_b;
	already = 0;
	while ((tmp_one && tmp_two)
	&& ((tmp_one != l_a && tmp_two != l_b) || !already))
	{
		tmp_one->dir[d_b] = tmp_two;
		tmp_one->dir[d_b]->dir[ft_tab_dir_reverse(d_b)] = tmp_one;
		tmp_one = tmp_one->dir[d_a];
		tmp_two = tmp_two->dir[d_a];
		already++;
	}
	return (0);
}
