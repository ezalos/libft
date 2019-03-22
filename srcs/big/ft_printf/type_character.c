/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:44:23 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/28 16:52:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_character(t_printf *print, char str)
{
	paste_char_in_printf(print, str);
	return (0);
}
