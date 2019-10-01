/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:12:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/10/01 15:44:48 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return ((char*)s + ft_strlen(s));
	while (*(char*)s != (char)c)
		if (*(s++) == 0)
			return (NULL);
	return ((char*)s);
}
