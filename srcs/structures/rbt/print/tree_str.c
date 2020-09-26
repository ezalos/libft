/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:03:38 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/26 21:03:48 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		tree_str(t_rbt *root)
{
	if (root != NULL)
	{
		if (root->color == RED)
			ft_printf("R%~{255;150;150}%d%~{}", root->key);
		else
			ft_printf("B%~{150;150;255}%d%~{}", root->key);
	}
	else
		ft_printf("null");
}
