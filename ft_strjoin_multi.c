/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:14:54 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/22 19:09:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_multi(size_t nb, ...)
{
	va_list 	ap;
	size_t		size_total;
	int			i;
	int			j;
	int			k;
	char		**srcs;
	char		*dest;

	if (nb < 2)
		return (NULL);
	if (!(srcs = (char**)malloc(sizeof(char*) * nb)))
		return (NULL);
	va_start(ap, nb);
	i = -1;
	size_total = 0;
	while (++i < (int)nb)
	{
		srcs[i] = va_arg(ap, char*);
		if (!srcs[i])
			return (NULL);
		size_total += ft_strlen(srcs[i]);
	}
	va_end(ap);
	if (!(dest = ft_strnew(size_total)))
		return (NULL);
	k = -1;
	i = -1;
	while (++i < (int)nb)
	{
		j = -1;
		while (srcs[i][++j])
			dest[++k] = srcs[i][j];
	}
	dest[size_total] = 0;
	return (dest);
}
