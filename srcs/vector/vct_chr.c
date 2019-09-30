/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:55:59 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 10:19:56 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	vct_chr(t_vector *vector, char c)
{
	size_t	index;

	index = 0;
	while (index <= vector->len)
	{
		if (vector->str[index] == c)
			return (index);
		index++;
	}
	return (FAILURE);
}
