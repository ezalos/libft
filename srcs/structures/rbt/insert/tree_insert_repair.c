/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert_repair.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:55:57 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/26 20:56:04 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		tree_insert_repair(t_rbt *n)
{
	if (tree_parent(n) == NULL)
	{
		tree_insert_case_1(n);
	}
	else if (tree_parent(n)->color == BLACK)
	{
		tree_insert_case_2(n);
	}
	else if (tree_uncle(n) != NULL && tree_uncle(n)->color == RED)
	{
		tree_insert_case_3(n);
	}
	else
	{
		tree_insert_case_4(n);
	}
}
