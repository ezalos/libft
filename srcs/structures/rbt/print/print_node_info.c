/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:04:41 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/26 21:04:49 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		print_node_info(t_rbt *root)
{
	if (root != NULL)
	{
		ft_printf("P ");
		tree_str(root->parent);
		ft_printf("\t");
		tree_str(root);
		ft_printf("\tl ");
		tree_str(root->left);
		ft_printf("\tr ");
		tree_str(root->right);
		ft_printf("\n");
		return (1);
	}
	else
		ft_printf("Null node\n");
	return (0);
}
