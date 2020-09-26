/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:53:58 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/26 20:55:41 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		tree_insert_case_1(t_rbt *n)
{
	n->color = BLACK;
}

void		tree_insert_case_2(t_rbt *n)
{
	// Do nothing since tree is still valid.
	(void)n;
	return;
}

void		tree_insert_case_3(t_rbt *n)
{
	tree_parent(n)->color = BLACK;
	tree_uncle(n)->color = BLACK;
	tree_grand_parent(n)->color = RED;
	tree_insert_repair(tree_grand_parent(n));
}

void		tree_insert_case_4(t_rbt *n)
{
	t_rbt *p = tree_parent(n);
	t_rbt *g = tree_grand_parent(n);

	if (n == p->right && p == g->left)
	{
		tree_rot_left(p);
		n = n->left;
	}
	else if (n == p->left && p == g->right)
	{
		tree_rot_right(p);
		n = n->right;
	}

	p = tree_parent(n);
	g = tree_grand_parent(n);
	if (n == p->left)
		tree_rot_right(g);
	else
		tree_rot_left(g);
	p->color = BLACK;
	g->color = RED;
}
