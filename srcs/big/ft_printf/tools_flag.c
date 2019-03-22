/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:45:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 12:15:13 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reajust_sign(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-')
		{
			str[i] = '0';
			str[0] = '-';
		}
		if (str[i] == '+')
		{
			str[i] = '0';
			str[0] = '+';
		}
	}
}

void	reajust_hatg(t_printf *print, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == 'x' || str[i] == 'X')
			str[i] = '0';
	if (str[0] == '0')
	{
		if (print->arg->type == 'x')
			str[1] = 'x';
		else if (print->arg->type == 'X')
			str[1] = 'X';
	}
}

int		add_minimum_width(t_printf *print, char **str)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = *str;
	if (print->arg->minimum_width > (len = ft_strlen(*str)))
	{
		if (!(tmp = ft_strnew(print->arg->minimum_width - len)))
			return (-1);
		ft_memset(tmp, print->arg->space_filled,
		print->arg->minimum_width - len);
	}
	if (print->arg->ajust_left && tmp)
		if (!(*str = ft_strjoin(*str, tmp)))
			return (-1);
	if (!print->arg->ajust_left && tmp)
		if (!(*str = ft_strjoin(tmp, *str)))
			return (-1);
	if (tmp)
	{
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	return (1);
}

int		add_precison(t_printf *print, char **str)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	tmp2 = *str;
	len = ft_strlen(*str);
	if (*str[0] == '-')
		len--;
	if (print->arg->precision > len)
	{
		if (!(tmp = ft_strnew(print->arg->precision - len)))
			return (-1);
		ft_memset(tmp, '0', print->arg->precision - len);
		if (!(*str = ft_strjoin(tmp, *str)))
			return (-1);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	return (1);
}
