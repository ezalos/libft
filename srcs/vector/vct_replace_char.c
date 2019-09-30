/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_replace_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:34:06 by amartino          #+#    #+#             */
/*   Updated: 2019/09/12 14:44:52 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Replace all given char of a string to the given replace char.
*/

int8_t			vct_replace_char(t_vector *vector, char c, char replace)
{
	size_t		index;

	index = 0;
	if (vector != NULL && vector->str != NULL)
	{
		while (index < vector->len)
		{
			if (vector->str[index] == c)
				vector->str[index] = replace;
			index++;
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
