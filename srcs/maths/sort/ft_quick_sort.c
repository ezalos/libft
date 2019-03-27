/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:38:25 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/27 22:05:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_choose_pivot(int **array, int low, int high, int *count)
{
	int		mid;

	mid = (low + high) / 2;
	if (mid == low || mid == high)
		return ((*array)[high]);
	if (((*array)[mid] < (*array)[low] && (*array)[low] < (*array)[high])
	|| ((*array)[mid] > (*array)[low] && (*array)[low] > (*array)[high]))
	{
		ft_swap(&(*array)[low], &(*array)[high], sizeof(int));
		(*count)++;
	}
	else if (((*array)[high] < (*array)[mid] && (*array)[mid] < (*array)[low])
		|| ((*array)[high] > (*array)[mid] && (*array)[mid]> (*array)[low]))
	{
		ft_swap(&(*array)[mid], &(*array)[high], sizeof(int));
		(*count)++;
	}
	return ((*array)[high]);
}

static int		ft_qs_partition(int **array, int low, int high, int *count)
{
	int		pivot;
	int		look_left;
	int		look_right;

    pivot = ft_choose_pivot(array, low, high, count);
	look_left = low;
	look_right = high - 1;

	while (look_left < look_right)
	{
        if ((*array)[look_left] > pivot)
		{
			if ((*array)[look_right] < pivot)
			{
				ft_swap(&(*array)[look_right], &(*array)[look_left], sizeof(int));
				(*count)++;
			}
			else
				look_right--;
		}
		else
			look_left++;
	}
	if ((*array)[look_left] > (*array)[high])
	{
		ft_swap(&(*array)[look_left], &(*array)[high], sizeof(int));
		(*count)++;
	}
	return (look_left);
}

void		ft_quick_sort(int **array, int low, int high, int *count)
{
	int		pivot;

    if (low < high)
    {
        pivot = ft_qs_partition(array, low, high, count);

        ft_quick_sort(array, low, pivot - 1, count);
        ft_quick_sort(array, pivot + 1, high, count);
    }
}
