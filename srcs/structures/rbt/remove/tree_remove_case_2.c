/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_remove_case_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:37:36 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 11:38:16 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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
