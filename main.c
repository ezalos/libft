/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:36:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/10/12 18:07:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

#define COMPRESS_TABLE	256

t_btree		*ft_create_node(t_btree *child_one, t_btree *child_two, int size, void *content)
{
	t_btree		*node;

	node = ft_memalloc(sizeof(t_btree));
	node->child[0] = child_one;
	node->child[1] = child_two;
	node->size = size;
	node->content = content;
}

int			ft_compare_list(t_list *one, t_list *two)
{
	return (((t_btree*)one->content)->size - ((t_btree*)two->content)->size);
}

void		ft_sort_list(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 1;
	while (i)
	{
		i = 0;
		tmp = lst;
		while (tmp->next)
		{
			if (ft_compare_list(tmp, tmp->next) > 0)
			{
				ft_swap(&tmp->content, &tmp->next->content, sizeof(void*));
				i++;
			}
			tmp = tmp->next;
		}
	}
}

t_list		*ft_fill_tab(char *file, int size, int *compress_table)
{
	t_list	*list;
	int		i;

	ft_bzero(compress_table, sizeof(int) * COMPRESS_TABLE);
	i = -1;
	while (++i < size)
		compress_table[file[i]]++;
	i = -1;
	while (++i < COMPRESS_TABLE)
		if (compress_table[i] > 0)
			ft_lstadd(&list, ft_create_node(NULL, NULL, compress_table[i], (void*)i), -1);
	return (list);
}

int 	ft_compress(char *path)
{
	int		compress_table[COMPRESS_TABLE];
	int		size;
	char	*file;

	size = ft_get_file(path, &file);
	make_binary_tree(ft_fill_tab(file, size, compress_table));
}



int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	(void)av;
	return (0);
}
