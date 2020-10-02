/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_remove_case_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:37:36 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 11:38:09 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		tree_delete_case_1(t_rbt *node)
{
	if (node->parent != NULL)
	{
		if (tree_sibling(node))
			tree_delete_case_2(node);
	}
}

void		tree_delete_case_2(t_rbt *node)
{
	t_rbt	*sibling;

	sibling = tree_sibling(node);
	if (sibling->color == RED)
	{
		node->parent->color = RED;
		sibling->color = BLACK;
		if (node == node->parent->left)
		{
			tree_rot_left(node->parent);
		}
		else
		{
			tree_rot_right(node->parent);
		}
	}
	tree_delete_case_3(node);
}

void		tree_delete_case_3(t_rbt *node)
{
	t_rbt	*sibling;

	sibling = tree_sibling(node);
	if ((node->parent->color == BLACK) && (sibling->color == BLACK)
	&& (sibling->left->color == BLACK) && (sibling->right->color == BLACK))
	{
		sibling->color = RED;
		tree_delete_case_1(node->parent);
	}
	else
	{
		tree_delete_case_4(node);
	}
}

void		tree_delete_case_4(t_rbt *node)
{
	t_rbt	*sibling;

	sibling = tree_sibling(node);
	if ((node->parent->color == RED) && (sibling->color == BLACK)
	&& (sibling->left->color == BLACK) && (sibling->right->color == BLACK))
	{
		sibling->color = RED;
		node->parent->color = BLACK;
	}
	else
	{
		tree_delete_case_5(node);
	}
}

void		tree_delete_case_5(t_rbt *node)
{
	t_rbt	*sibling;

	sibling = tree_sibling(node);
	if (sibling->color == BLACK)
	{
		if ((node == node->parent->left) && (sibling->right->color == BLACK)
		&& (sibling->left->color == RED))
		{
			sibling->color = RED;
			sibling->left->color = BLACK;
			tree_rot_right(sibling);
		}
		else if ((node == node->parent->right)
		&& (sibling->left->color == BLACK) && (sibling->right->color == RED))
		{
			sibling->color = RED;
			sibling->right->color = BLACK;
			tree_rot_left(sibling);
		}
	}
	tree_delete_case_6(node);
}
