/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rgbcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:29:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/10/22 01:01:30 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_middle(char *nb_str, intmax_t n)
{
	size_t		size;

	if (n <= 0)
		n = -n;
	if (n > 255)
		n = 255;
	size = ft_nb_len(n, 10);
	ft_putbnbr_str(size - 1, n, nb_str, 10);
	return (size + 1);
}

char			*ft_str_rgbcolor(char background, int red, int green, int blue)
{
	char		*color;
	size_t		cursor;

	if ((color = ft_memalloc(20)))
	{
		ft_memmove(color, "\x1b[38;2;", 7);
		if (background)
			color[2] = '4';
		cursor = 7;
		cursor += ft_middle(color + cursor, red);
		color[cursor - 1] = ';';
		cursor += ft_middle(color + cursor, green);
		color[cursor - 1] = ';';
		cursor += ft_middle(color + cursor, blue);
		color[cursor - 1] = 'm';
	}
	return (color);
}
