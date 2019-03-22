/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:44:59 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 15:33:49 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** if (**f == '>')
** 	cursor_gestion(print, f);
**
** else if (**f == '[')
** 	tab_gestion(print, f);
*/

int		bonus_gestion(t_printf *print, const char **f)
{
	int		fd;

	ft_bzero(print->bonus, sizeof(print->bonus));
	(*f)++;
	print->bonus->exist = **f;
	if (**f == '{')
		color_gestion(print, f);
	else if (**f == '.')
	{
		(*f)++;
		print->fd = (size_t)get_value_of_star_or_nb(print, f, &fd);
	}
	return (0);
}
