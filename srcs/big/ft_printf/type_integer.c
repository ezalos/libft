/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:54:06 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/28 17:38:28 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_nb_len(intmax_t n, size_t base)
{
	size_t		size;
	uintmax_t	nb;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		nb = -n;
	}
	else
		nb = n;
	if (base == 0)
		base = 10;
	while (nb != 0)
	{
		nb /= base;
		size++;
	}
	return (size);
}

void		ft_putnbr_str(int i, uintmax_t n, char *nb, size_t base)
{
	char	*base_smbl;

	base_smbl = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOQRSTUVWXYZ";
	if (base > 62)
		base = 62;
	while (i >= 0 && nb[i] != '-')
	{
		nb[i] = base_smbl[n % base];
		n /= base;
		i--;
	}
}

char		*ft_nb_to_a(intmax_t n, size_t base)
{
	char		*nb_str;
	size_t		size;
	int			neg;
	uintmax_t	nb;

	neg = 1;
	if (n >= 0)
		neg = 0;
	if (base == 0)
		base = 10;
	size = ft_nb_len(n, base);
	if (!(nb_str = ft_strnew(size)))
		return (NULL);
	if (neg == 1)
	{
		nb_str[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	ft_putnbr_str(size - 1, nb, nb_str, base);
	return (nb_str);
}

int			print_integer(t_printf *print, intmax_t nb)
{
	int	base;

	base = 10;
	print->last_type = ft_nb_to_a(nb, base);
	paste_int_in_printf(print, print->last_type);
	return (0);
}
