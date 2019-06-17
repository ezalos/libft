/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seed_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:55:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/13 23:51:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_seed_string(const char *str)
{
	intmax_t	seed;
	intmax_t	seedo;
	int			len;
	int			i;

	len = ft_strlen(str);
	seed = 0;
	i = -1;
	while (++i < len)
		seed += (int)str[i] * (i + 1);
	seedo = *str++;
	while (*str)
		seedo ^= *str++;
	return (seed * seedo);
}
