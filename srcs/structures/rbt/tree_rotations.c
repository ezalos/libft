/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:29:12 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 11:40:03 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	tree_rot_left(t_rbt *node)
{
	t_rbt	*old_root;
	t_rbt	*parent;
	t_rbt	*new_root;

	old_root = node;
	parent = tree_parent(old_root);
	new_root = old_root->right;
	old_root->right = new_root->left;
	new_root->left = old_root;
	old_root->parent = new_root;
	if (old_root->right != NULL)
		old_root->right->parent = old_root;
	if (parent != NULL)
	{
		if (parent->right == old_root)
			parent->right = new_root;
		else
			parent->left = new_root;
		new_root->parent = parent;
	}
	else
		new_root->parent = NULL;
}

void	tree_rot_right(t_rbt *node)
{
	t_rbt	*old_root;
	t_rbt	*parent;
	t_rbt	*new_root;

	old_root = node;
	parent = tree_parent(old_root);
	new_root = old_root->left;
	old_root->left = new_root->right;
	new_root->right = old_root;
	old_root->parent = new_root;
	if (old_root->left != NULL)
		old_root->left->parent = old_root;
	if (parent != NULL)
	{
		if (parent->left == old_root)
			parent->left = new_root;
		else
			parent->right = new_root;
		new_root->parent = parent;
	}
	else
		new_root->parent = NULL;
}
