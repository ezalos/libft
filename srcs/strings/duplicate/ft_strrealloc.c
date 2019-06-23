/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:51:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/23 16:55:07 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrealloc(const char *src, size_t size)
{
	char	*str;

	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	str = ft_strcpy(str, src);
	ft_strdel((char**)&src);
	return (str);
}
