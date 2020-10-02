/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_inorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:00:17 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 11:28:30 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int					tree_inorder(t_rbt *root, t_rbt_inorder *func)
{
	int				value;

	value = 0;
	if (root != NULL)
	{
		value += tree_inorder(root->left, func);
		value += func(root);
		value += tree_inorder(root->right, func);
	}
	return (value);
}

void				*tree_inorder_ptr(t_rbt *root, t_rbt_inorder_ptr *func)
{
	long long		value;

	value = 0;
	if (root != NULL)
	{
		value += (long long)tree_inorder_ptr(root->left, func);
		value += (long long)func(root);
		value += (long long)tree_inorder_ptr(root->right, func);
	}
	return ((void*)value);
}

long long			tree_inorder_long_long(t_rbt *root,
					t_rbt_inorder_long_long *func)
{
	long long		value;

	value = 0;
	if (root != NULL)
	{
		value += (long long)tree_inorder_long_long(root->left, func);
		value += (long long)func(root);
		value += (long long)tree_inorder_long_long(root->right, func);
	}
	return (value);
}
