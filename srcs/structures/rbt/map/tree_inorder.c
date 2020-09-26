/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_inorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:00:17 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/26 21:00:44 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			tree_inorder(t_rbt *root, t_rbt_inorder *func)
{
	int		value = 0;

	if (root != NULL)
	{
		value += tree_inorder(root->left, func);
		value += func(root);
		value += tree_inorder(root->right, func);
	}
	return value;
}
