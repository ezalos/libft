/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert_recurse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:46:48 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/26 20:56:59 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		tree_insert_recurse(t_rbt *root, t_rbt *n)
{
	if (root != NULL)
	{
		if (n->key < root->key)
			if (root->left != NULL)
			{
				tree_insert_recurse(root->left, n);
				return;
			}
			else
				root->left = n;
		else
			if (root->right != NULL)
			{
				tree_insert_recurse(root->right, n);
				return;
			}
			else
				root->right = n;
	}
	n->parent = root;
	n->left = NULL;
	n->right = NULL;
	n->color = RED;
}

void		tree_insert_recurse_func(t_rbt *root, t_rbt *n, t_rbt_compare *func)
{
	if (root != NULL)
	{
		if (func(root->content, n->content) > 0)
			if (root->left != NULL)
			{
				tree_insert_recurse_func(root->left, n, func);
				return;
			}
			else
				root->left = n;
		else
			if (root->right != NULL)
			{
				tree_insert_recurse_func(root->right, n, func);
				return;
			}
			else
				root->right = n;
	}
	n->parent = root;
	n->left = NULL;
	n->right = NULL;
	n->color = RED;
}
