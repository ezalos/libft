/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:11:36 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 11:37:26 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		tree_replace_node(t_rbt *node, t_rbt *child)
{
	child->parent = node->parent;
	if (node == node->parent->left)
		node->parent->left = child;
	else
		node->parent->right = child;
}

void		tree_delete_one_child(t_rbt *node, t_rbt_free_content *func)
{
	t_rbt	*child;

	if (node->right == NULL)
		child = node->left;
	else
		child = node->right;
	if (child)
	{
		tree_replace_node(node, child);
		if (node->color == BLACK)
		{
			if (child->color == RED)
				child->color = BLACK;
			else
				tree_delete_case_1(child);
		}
	}
	if (func)
		func(&node->content);
	ft_memdel((void**)&node);
}
