/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:42:52 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/26 20:42:53 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_rbt		*tree_new_node(void *content)
{
   t_rbt		*node;

   node = ft_memalloc(sizeof(t_rbt));
   node->content = content;
   node->color = RED;
   node->parent = NULL;
   node->left = NULL;
   node->right = NULL;
   return (node);
}
