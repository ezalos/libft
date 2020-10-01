/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:11:36 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/30 14:54:46 by ezalos           ###   ########.fr       */
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
	// This if statement is trivial, due to case 2 (even though case 2 changed
	// the sibling to a sibling's child, the sibling's child can't be red, since
	// no red parent can have a red child).
	if (sibling->color == BLACK)
	{
		// The following statements just force the red to be on the left of the
		// left of the parent, or right of the right, so case six will rotate
		// correctly.
		if ((node == node->parent->left) && (sibling->right->color == BLACK)
		&& (sibling->left->color == RED))
		{
			// This last test is trivial too due to cases 2-4.
			sibling->color = RED;
			sibling->left->color = BLACK;
			tree_rot_right(sibling);
		}
		else if ((node == node->parent->right)
		&& (sibling->left->color == BLACK) && (sibling->right->color == RED))
		{
			// This last test is trivial too due to cases 2-4.
			sibling->color = RED;
			sibling->right->color = BLACK;
			tree_rot_left(sibling);
		}
	}
	tree_delete_case_6(node);
}

void		tree_delete_case_6(t_rbt *node)
{
	t_rbt	*sibling;

	sibling = tree_sibling(node);
	sibling->color = node->parent->color;
	node->parent->color = BLACK;

	if (node == node->parent->left)
	{
		sibling->right->color = BLACK;
		tree_rot_left(node->parent);
	}
	else
	{
		sibling->left->color = BLACK;
		tree_rot_right(node->parent);
	}
}
