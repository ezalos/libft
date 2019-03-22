/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rgbcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:29:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 14:35:43 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_str_rgbcolor(char background, int red, int green, int blue)
{
	char		*color;
	char		*s_red;
	char		*s_green;
	char		*s_blue;

	if (!(s_red = ft_nb_to_a(red, 10)))
		return (NULL);
	if (!(s_green = ft_nb_to_a(green, 10)))
		return (NULL);
	if (!(s_blue = ft_nb_to_a(blue, 10)))
		return (NULL);
	if (background)
	{
		if (!(color = ft_strjoin_multi(7, "\x1b[48;2;", s_red, ";", s_green,
		";", s_blue, "m")))
			return (NULL);
	}
	else if (!(color = ft_strjoin_multi(7, "\x1b[38;2;", s_red, ";", s_green,
		";", s_blue, "m")))
		return (NULL);
	ft_strdel(&s_green);
	ft_strdel(&s_blue);
	ft_strdel(&s_red);
	return (color);
}
