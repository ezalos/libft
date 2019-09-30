/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:30:22 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 10:57:44 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Free the vector and set it to NULL
*/

void			vct_del(t_vector **vector)
{
	if (*vector != NULL && (*vector)->str != NULL)
		ft_strdel(&((*vector)->str));
	ft_memdel((void**)vector);
}
