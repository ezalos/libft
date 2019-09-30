/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_newstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:23:18 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 10:20:51 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Return a new vector initialized with a string;
**
**	The size parameter is the lenght of the string with the '\0'.
*/

t_vector	*vct_newstr(char *str)
{
	t_vector	*new_vector;
	size_t		len;

	new_vector = NULL;
	if (str != NULL)
	{
		len = ft_strlen(str);
		new_vector = (t_vector *)ft_memalloc(sizeof(t_vector));
		if (new_vector != NULL)
		{
			new_vector->size = len + 1;
			new_vector->len = len;
			new_vector->scale = DEFAULT_VCT_SCALE;
			new_vector->str = ft_memalloc(new_vector->size);
			if (new_vector->str == NULL)
				vct_del(&new_vector);
			else
				ft_memcpy(new_vector->str, str, new_vector->len + 1);
		}
	}
	return (new_vector);
}
