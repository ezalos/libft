/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloco.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 07:34:16 by gtaja             #+#    #+#             */
/*   Updated: 2019/11/03 15:33:22 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*malloco(size_t size_content)
{
	if ((*switch_garbage()) == TRUE)
		return (nalloc(size_content));
	else
		return (malloc(size_content));
}
