/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:15:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/27 16:36:15 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**	dir[0] : up;
**	dir[1] : right;
**	dir[2] : down;
**	dir[3] : left;
*/

#include "libft.h"
/*
t_tab	*ft_tab_access(t_tab *tab, int dir_zer, int dir_one, int dir_two, int dir_thr)
{
	t_tab	*tmp;

	if (dir_zer < 0 || dir_one < 0 || dir_two < 0 || dir_thr < 0)
	{

	}
	return (tmp);
}
*/
t_tab	*ft_tabnew_rectangle(size_t x_axis, size_t y_axis, size_t x_dir)
{
	t_tab	*tab;
	t_tab	*tmp;
	t_tab	*tmp_old;
	size_t	i;

	if (!x_axis || x_dir > 3)
		return (NULL);
	if (!(tab = ft_tabnew_dir(y_axis, x_dir)))
		return (NULL);
	tmp = tab;
	tmp_old = NULL;
	i = 0;
	while (i < y_axis && x_axis > 1)
	{
		if(!(tmp->dir[ft_tab_dir_rclock(x_dir)] = ft_tabnew_dir(x_axis - 1, ft_tab_dir_rclock(x_dir))))
			return (NULL);
		tmp->dir[ft_tab_dir_rclock(x_dir)]->dir[ft_tab_dir_clock(x_dir, 1)] = tmp;
		if (tmp_old && tmp)
			ft_tab_connect_dir(ft_tab_dir_rclock(x_dir), tmp_old, tmp, x_dir);

		tmp_old = tmp;
		tmp = tmp->dir[x_dir];
		i++;
	}
	return (tab);
}

int		main(int ac, char **av)
{
	t_tab	*tab;

	if (ac < 3)
		return (0);
//	tab = ft_tabnew_dir(ft_atoi(av[1]), 2);
//	ft_tab_square_it(tab, 2);
	tab = ft_tabnew_rectangle(ft_atoi(av[1]), ft_atoi(av[2]), 2);
	ft_rgb_bcolor(20, 20, 20);
	ft_tabiter(tab, 2, &ft_tab_print_dir, 1);
	return (0);
}
