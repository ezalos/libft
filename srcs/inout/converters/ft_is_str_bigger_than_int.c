/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_bigger_than_int.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:15:34 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 19:15:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		int_maxou_three(char *str)
{
	if (str[9] > '7')
		return (1);
	if (str[9] < '7')
		return (0);
	return (0);
}

static int		int_maxou_two(char *str)
{
	if (str[3] > '7')
		return (1);
	if (str[4] < '4')
		return (0);
	if (str[4] > '4')
		return (1);
	if (str[5] > '8')
		return (1);
	if (str[5] < '8')
		return (0);
	if (str[6] > '3')
		return (1);
	if (str[6] < '3')
		return (0);
	if (str[7] > '6')
		return (1);
	if (str[7] < '6')
		return (0);
	if (str[8] > '4')
		return (1);
	if (str[8] < '4')
		return (0);
	return (int_maxou_three(str));
}

static int		minus_maxou(char *str)
{
	int	out;

	str++;
	if (str[9] == '8')
	{
		str[9] = '7';
		out = ft_is_str_bigger_than_int(str);
		str[9] = '8';
	}
	else
	{
		out = ft_is_str_bigger_than_int(str);
	}
	return (out);
}

int				ft_is_str_bigger_than_int(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len < 10)
		return (0);
	if ((len > 10 && str[0] != '-') || (len > 11 && str[0] == '-'))
		return (1);
	if (str[0] == '-')
		return (minus_maxou(str));
	if (str[0] < '2')
		return (0);
	if (str[0] > '2')
		return (1);
	if (str[1] < '1')
		return (0);
	if (str[1] > '1')
		return (1);
	if (str[2] > '4')
		return (1);
	if (str[2] < '4')
		return (0);
	if (str[3] < '7')
		return (0);
	return (int_maxou_two(str));
}
