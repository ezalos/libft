/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:51:54 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 12:15:49 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*s_to_bin(unsigned char *str, int length)
{
	char		*binary;
	int			actual_char;
	int			power;

	if (!(binary = ft_strnew(length * (8 + 1))))
		return (NULL);
	actual_char = -1;
	while (++actual_char < length)
	{
		power = -1;
		while (++power < 8)
			if (str[actual_char] & (unsigned char)ft_power(2, power))
				binary[(actual_char * 9) + (power)] = '1';
			else
				binary[(actual_char * 9) + (power)] = '0';
		binary[(actual_char * 9) + (power)] = ' ';
	}
	return (binary);
}

char		*ft_strrev(char *str, size_t size)
{
	char		tmp;
	int			i;
	int			j;

	i = 0;
	if (size != 0)
		j = size - 1;
	else
		j = ft_strlen((char*)str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		j--;
		i++;
	}
	return (str);
}

char		*print_string_to_binary(unsigned char *converter, size_t size_thing)
{
	char		*tmp1;

	tmp1 = s_to_bin(converter, size_thing);
	ft_memdel((void**)&converter);
	ft_strrev(tmp1, (size_thing * 9) - 1);
	return (tmp1);
}

int			print_binary(t_printf *print, void *bin)
{
	char		*tmp1;
	char		*tmp2;

	if (!bin)
	{
		tmp2 = ft_strdup("0x0");
	}
	else
	{
		if (!print->arg->precision)
			print->arg->precision = 1;
		tmp1 = print_string_to_binary((unsigned char*)bin,
		(size_t)print->arg->precision);
		tmp2 = (char*)tmp1;
	}
	get_printf(print, &tmp2, ft_strlen(tmp2));
	return (0);
}
