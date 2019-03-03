/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:15:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/03 23:32:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**	dir[0] : up;
**	dir[1] : right;
**	dir[2] : down;
**	dir[3] : left;
*/

#include "libft.h"

void		ft_tab_connect_structs(t_tab *tab_one, t_tab *tab_two, size_t dir_one)
{
	size_t	dir_two;

	dir_two = ft_tab_dir_reverse(dir_one);
	tab_one->dir[dir_one] = tab_two;
	tab_two->dir[dir_two] = tab_one;
}

size_t			ft_tab_delete_row(t_tab *tab, size_t dir)
{
	t_tab	*tmp;
	t_tab	*next;
	size_t	i;

	tmp = tab;
	i = 0;
	ft_tab_connect_dir(dir, tab->dir[ft_tab_dir_clock(dir)], tab->dir[ft_tab_dir_rclock(dir)], ft_tab_dir_clock(dir));
	while (tmp)
	{
		tmp->dir[ft_tab_dir_reverse(dir)] = NULL;
		next = tmp->dir[dir];
		ft_memdel((void**)&tmp);
		tmp = next;
		i++;
	}
	return (i);
}

size_t			ft_tab_delete_row_len(t_tab *tab, size_t dir, size_t len)
{
	t_tab	*tmp;
	t_tab	*next;
	size_t	i;

	tmp = tab;
	i = 0;
	if (!len)
		return (ft_tab_delete_row(tab, dir));
	while (tmp && i < len)
	{
		tmp->dir[ft_tab_dir_reverse(dir)] = NULL;
		ft_tab_connect_structs(tmp->dir[ft_tab_dir_clock(dir)], tmp->dir[ft_tab_dir_rclock(dir)], ft_tab_dir_rclock(dir));
		next = tmp->dir[dir];
		ft_memdel((void**)&tmp);
		tmp = next;
		i++;
	}
	return (i);
}

static void	ft_tab_access_setup(size_t *down, size_t *right, int *dir_y, int *dir_x)
{
	if (*dir_x < 0)
	{
		*dir_x = -*dir_x;
		*right = ft_tab_dir_reverse(*right);
	}
	if (*dir_y < 0)
	{
		*dir_y = -*dir_y;
		*down = ft_tab_dir_reverse(*down);
	}
}

t_tab	*ft_tab_access(t_tab *tab, int dir_y, int dir_x, int rot)
{
	t_tab	*tmp;
	size_t	down;
	size_t	right;

	down = 2;
	right = 1;
	ft_tab_access_setup(&down, &right, &dir_y, &dir_x);
	if (rot)
	{
		right = ft_tab_dir_nclock(right, rot);
		down = ft_tab_dir_nclock(down, rot);
	}
	tmp = tab;
	while (tmp)
	{
		while (dir_y-- && tmp->dir[down])
			tmp = tmp->dir[down];
		while (dir_x-- && tmp->dir[righ])
			tmp = tmp->dir[right];
	}
	return (tmp);
}

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
		tmp->dir[ft_tab_dir_rclock(x_dir)]->dir[ft_tab_dir_clock(x_dir)] = tmp;
		if (tmp_old && tmp)
			ft_tab_connect_dir(ft_tab_dir_rclock(x_dir), tmp_old, tmp, x_dir)
		tmp_old = tmp;
		tmp = tmp->dir[x_dir];
		i++;
	}
	return (tab);
}

int		ft_tab_parser(t_tab **god, int fd)
{
	char		*my_command;

	get_next_line(0, &my_command);
	while (my_command)
	{

	}
}

int		main(int ac, char **av)
{
	t_tab	*tab;

	if (ac == 1)
		if (!ft_tab_parser(&tab))
			return (-1);
	else if (ac <=3)
		return (0);
//	tab = ft_tabnew_dir(ft_atoi(av[1]), 2);
//	ft_tab_square_it(tab, 2);

	tab = ft_tabnew_rectangle(ft_atoi(av[1]), ft_atoi(av[2]), 2);
	ft_rgb_bcolor(20, 20, 20);
	ft_tabiter(tab, 2, &ft_tab_print_dir, 1);
	return (0);
}
