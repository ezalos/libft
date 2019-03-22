/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:06:10 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/01 15:44:34 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			paste_char_in_printf(t_printf *print, char str)
{
	char	*my_char;

	if (!(my_char = ft_strnew(1)))
		return (0);
	my_char[0] = str;
	if (str == 0)
	{
		get_printf(print, &my_char, 1);
		return (1);
	}
	ajust_flags(print, &my_char);
	get_printf(print, &my_char, ft_strlen(my_char));
	return (1);
}
