/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_flag2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:45:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/20 19:10:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_htag(t_printf *print, char **str)
{
	char	*tmp;

	if (print->arg->htag)
	{
		tmp = *str;
		if (print->arg->type == 'o')
		{
			if (!(*str = ft_strjoin("0", tmp)))
				return (-1);
		}
		else if (print->arg->type == 'X')
		{
			if (!(*str = ft_strjoin("0X", tmp)))
				return (-1);
		}
		else if (print->arg->type == 'x')
			if (!(*str = ft_strjoin("0x", tmp)))
				return (-1);
		ft_strdel(&tmp);
	}
	return (0);
}

int		add_sign(char **str)
{
	char	*tmp;

	tmp = *str;
	if (!(*str = ft_strjoin("+", *str)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

int		add_space(t_printf *print, char **str)
{
	char	*tmp;

	if (!print->arg->precision_exist && print->arg->minimum_width)
	{
		**str = ' ';
		return (1);
	}
	tmp = *str;
	if (!(*str = ft_strjoin(" ", *str)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

void	reajust_p(char *str)
{
	int		i;

	i = 0;
	if (str[1] == '0' && str[0] == '0')
	{
		while (str[i] != 'x')
			i++;
		str[i] = '0';
		str[1] = 'x';
	}
}

int		type_p(char **str, t_printf *print)
{
	if (print->arg->precision_exist)
	{
		print->arg->precision += 2;
		if (add_precison(print, str) == -1)
			return (-1);
	}
	if (add_minimum_width(print, str) == -1)
		return (-1);
	if (print->arg->precision_exist && print->arg->precision == 2
		&& (*str)[2] == '0' && (*str)[3] == 0)
		(*str)[2] = 0;
	reajust_p(*str);
	return (1);
}
