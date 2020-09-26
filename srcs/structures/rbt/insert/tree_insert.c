/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:56:28 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/26 20:57:57 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_rbt		*tree_insert(t_rbt *root, void* content, int key)
{
	t_rbt	*n = tree_new_node(content);
	n->key = key;
	tree_insert_recurse(root, n);
	tree_insert_repair(n);
	root = tree_root(n);
	return root;
}

t_rbt		*tree_insert_func(t_rbt *root, void* content, t_rbt_compare *func)
{
	t_rbt	*n = tree_new_node(content);
	n->key = 0;
	tree_insert_recurse_func(root, n, func);
	tree_insert_repair(n);
	root = tree_root(n);
	return root;
}
