/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:28:05 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/30 10:40:44 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void				tree_free(t_rbt *root, t_rbt_free_content *func)
{
	if (root != NULL)
	{
		tree_free(root->left, func);
		func(&root->content);
		tree_free(root->right, func);
		ft_memdel((void**)&root);
	}
}
