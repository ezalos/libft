/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:15:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/23 19:14:45 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
typedef	struct		s_tab
{
	struct s_tab	*down;
	struct s_tab	*right;
	void			*content;
	size_t			content_size;
	struct s_tab	*up;
	struct s_tab	*left;
}					t_tab;
*/


typedef	struct		s_tab
{
	struct s_tab	*dir[4];
	void			*content;
	size_t			content_size;
}					t_tab;

/*
**	dir[0] : up;
**	dir[1] : right;
**	dir[2] : down;
**	dir[3] : left;
*/

int		ft_tab_print_fourdir(t_tab *tmp, size_t lin, size_t col, int structh)
{
	char				*complete;
	size_t				addr;
	unsigned char		color;

	//ft_putnbr(col);
	addr = 12;
	complete = "         ";
	place_cursor(lin, col);
	ft_putnbr(structh);
	place_cursor(lin, col + addr);
	color = (unsigned char)tmp->dir[0];//	UP

	ft_putstr_color(ft_nb_to_a((intmax_t)tmp->dir[0], 16), ft_random(0, 255, color, 1), ft_random(0, 255, color / 2, 1), ft_random(0, 255, color + 3, 1));
	if (!tmp->dir[0])
		ft_putstr(complete);


	place_cursor(lin + 1, col);
	color = (unsigned char)tmp->dir[3];//	LEFT
	ft_putstr_color(ft_nb_to_a((intmax_t)tmp->dir[3], 16), color, color / 2, color / 3);
	if (!tmp->dir[3])
		ft_putstr(complete);
	ft_putstr_color("|", 255, 255, 255);

	color = (unsigned char)tmp;//			HERE
	ft_putstr_color(ft_nb_to_a((intmax_t)tmp, 16), color, color, color);
	if (!tmp)
		ft_putstr(complete);
	ft_putstr_color("|", 255, 255, 255);

	color = (unsigned char)tmp->dir[1];//	RIGHT
	ft_putstr_color(ft_nb_to_a((intmax_t)tmp->dir[1], 16), color, color, color);
	if (!tmp->dir[1])
		ft_putstr(complete);


	place_cursor(lin + 2, col + addr);
	color = (unsigned char)tmp->dir[2];//	DOWN
	ft_putstr_color(ft_nb_to_a((intmax_t)tmp->dir[2], 16), color, color, color);
	if (!tmp->dir[2])
		ft_putstr(complete);
	return (0);
}

int		ft_tab_print_dir(t_tab *tab, size_t dir, int lin)
{
	t_tab	*tmp;
	int		structh;
	int		col;

	if (!tab || dir > 3)
		return (-1);
	//	printf("HELLO WORLD\n");
	tmp = tab;
	structh = 0;
	col = 3;
	//ft_rgb_bcolor((int) tab % 255, (int) tab % 255 , 0);
	//CURSOR_SAVE
	while (tmp)
	{
		ft_tab_print_fourdir(tmp, lin, col, structh);
		tmp = tmp->dir[dir];
		structh++;
		col += (12 * 3) + 2;
	}
	//C_RESET
	//CURSOR_LOAD
	ft_putstr("\n\n\n");
	return (1);
}

t_tab		*ft_tabnew_ptr(void const *content, size_t content_size)
{
	t_tab		*new;

	if (!(new = (t_tab*)malloc(sizeof(t_tab))))
		return (NULL);
	ft_bzero(new, sizeof(t_tab));
	if (content_size && content != NULL)
	{
		new->content_size = content_size;
		if (!content_size || !(new->content = malloc(content_size)))
			return (NULL);
		ft_memmove(new->content, (void*)content, content_size);
	}
	return (new);
}


size_t		ft_tab_lendir(t_tab *tab, size_t dir)
{
	t_tab	*tmp;
	size_t	i;

	if (!tab || dir > 3)
		return (0);
	tmp = tab;
	i = 1;
	while (tmp->dir[dir])
	{
		tmp = tmp->dir[dir];
		i++;
	}
	return (i);
}

t_tab		*ft_tab_dirth(t_tab *tab, size_t dir, size_t umpteenth)
{
	t_tab	*tmp;
	size_t	i;

	if (!tab || dir > 3)
		return (0);
	tmp = tab;
	i = 1;
	while (tmp->dir[dir] && i >= umpteenth)
	{
		tmp = tmp->dir[dir];
		i++;
	}
	return (tmp);
}

size_t		ft_tab_dir_clock(size_t dir, size_t move)
{
	dir += move;
	dir %= 4;
	return (dir);
}

size_t		ft_tab_dir_rclock(size_t dir)
{
	dir += 3;
	dir %= 4;
	return (dir);
}

size_t		ft_tab_dir_reverse(size_t dir)
{
	return (ft_tab_dir_clock(dir, 2));
}

t_tab		*ft_tabnew_dir(size_t len, size_t dir)
{
	t_tab	*head;
	t_tab	*col;
	int		i;

	if (!len || dir > 3 || !(head = ft_tabnew_ptr(NULL, 0)))
		return (NULL);
	col = head;
	i = -1;
	while (++i < (int)len)
	{
		if (!(col->dir[dir] = ft_tabnew_ptr(NULL, 0)))
			return (NULL);
		col->dir[dir]->dir[ft_tab_dir_reverse(dir)] = col;
		col = col->dir[dir];
	}
//	ft_tab_print_dir(head, dir);
	return (head);
}

int			ft_tab_connect_dir(size_t dir_line, t_tab *line_one, t_tab *line_two, size_t dir_connec)
{
	t_tab	*tmp_one;
	t_tab	*tmp_two;

	if (!line_one || dir_line > 3 || !line_two || dir_connec > 3)
		return (-1);
	tmp_one = line_one;
	tmp_two = line_two;
	while (tmp_one->dir[dir_line] || tmp_two->dir[dir_line])
	{
		if (!tmp_one && tmp_two)
			return (1);
		else if (!tmp_two)
			return (2);
		tmp_one->dir[dir_connec] = tmp_two;
		tmp_two->dir[ft_tab_dir_reverse(dir_connec)] = tmp_one;
		tmp_one = tmp_one->dir[dir_line];
		tmp_two = tmp_two->dir[dir_line];
	}
	return (0);
}

t_tab	*ft_tab_square_it(t_tab *tab, size_t dir)
{
	t_tab		*tmp;
	t_tab		*tmp_old;
	size_t		len;
	size_t		perp_dir;

	if (!tab || dir > 3)
		return (NULL);
	tmp = tab;
	tmp_old = NULL;
	len = ft_tab_lendir(tab, dir);
	perp_dir = ft_tab_dir_rclock(dir);
	//int i = 0;
	while (tmp->dir[dir])
	{
		//printf("%d - len %zu\n", i++, len);
		tmp->dir[perp_dir] = ft_tabnew_dir(len, perp_dir);
		tmp->dir[perp_dir]->dir[ft_tab_dir_reverse(perp_dir)] = tmp;
		if (tmp_old)
			ft_tab_connect_dir(ft_tab_dir_reverse(perp_dir), tmp, tmp_old, dir);
		//ft_tab_dirth(tab, dir, len)->dir[ft_tab_dir_reverse(perp_dir)] = ft_tab_dirth(tmp, perp_dir, len);
		//ft_tab_dirth(tmp, perp_dir, len)->dir[perp_dir] = ft_tab_dirth(tab, dir, len);
		tmp_old = tmp;
		tmp = tmp->dir[dir];
	}
	return (tab);
}

void	ft_tabiter(t_tab *tab, size_t dir, int(*f)(t_tab *, size_t, int), size_t dirf)
{
	t_tab	*ptr;
	int 	i;
	int		lin;

	if (tab != NULL && f != NULL)
	{
		//ft_putstr("1\n");
		ptr = tab;
		lin = 3;
		while (ptr->dir[dir] != NULL)
		{
			//ft_putstr("|\n");
			i = (*f)(ptr, dirf, lin);
			ptr = ptr->dir[dir];
			lin += 4;
		}
		f(ptr, dirf, lin);
	}
}

int		main(void)
{
	t_tab	*tab;

	//ft_putstr("1\n");
	tab = ft_tabnew_dir(10, 2);
	//ft_putstr("2\n");
	ft_tab_square_it(tab, 2);
	//ft_putstr("3\n");
	//printf("\n\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n");
	//CLEAR_SCREEN
	ft_rgb_bcolor(20, 20, 20);
	ft_tabiter(tab, 2, &ft_tab_print_dir, 1);
	return (0);
}
