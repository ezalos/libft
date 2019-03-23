/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:09:01 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/23 19:21:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_str_2(int i, int n, char *nb)
{
	while (i >= 0 && nb[i] != '-')
	{
		nb[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char		*ft_itoa(int n)
{
	char	*nb;
	int		size;
	int		neg;
	int		i;

	neg = 1;
	if (n >= 0)
		neg = 0;
	size = ft_intlen(n);
	if (!(nb = ft_strnew(size)))
		return (NULL);
	if (neg == 1)
	{
		if (n == -2147483648)
			return (ft_strcpy(nb, "-2147483648"));
		nb[0] = '-';
		n = -n;
	}
	i = size;
	ft_putnbr_str_2(i - 1, n, nb);
	return (nb);
}
