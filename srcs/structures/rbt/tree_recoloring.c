/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_recoloring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:44:09 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/26 20:44:15 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		tree_recoloring(t_rbt *node)
{
	if (node->parent == NULL)
		node->color = BLACK;
	else if (node->parent->color != BLACK)
	{
		if (tree_uncle(node)->color == RED)
		{
			node->parent->color = BLACK;
			tree_uncle(node)->color = BLACK;

		}
	}
}
