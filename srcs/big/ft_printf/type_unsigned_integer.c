/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_unsigned_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:52:49 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 17:34:36 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_u_nb_len(uintmax_t nb, size_t base)
{
	size_t size;

	if (nb == 0)
		return (1);
	size = 0;
	if (base == 0)
		base = 10;
	while (nb != 0)
	{
		nb /= base;
		size++;
	}
	return (size);
}

static void		ft_putnbr_str(int i, uintmax_t n, char *nb, size_t base)
{
	char	*base_smbl;

	base_smbl = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (base > 36)
		base = 36;
	while (i >= 0 && nb[i] != '-')
	{
		nb[i] = base_smbl[n % base];
		n /= base;
		i--;
	}
}

char			*ft_u_nb_to_a(uintmax_t n, size_t base)
{
	char		*nb_str;
	size_t		size;
	uintmax_t	nb;

	size = ft_u_nb_len(n, base);
	if (!(nb_str = ft_strnew(size)))
		return (NULL);
	else
		nb = n;
	ft_putnbr_str(size - 1, nb, nb_str, base);
	return (nb_str);
}

int				print_unsigned_integer(t_printf *print, uintmax_t nb)
{
	int		base;
	int		i;

	base = 10;
	if (print->arg->type == 'o')
		base = 8;
	else if (print->arg->type == 'x' || print->arg->type == 'X')
		base = 16;
	print->last_type = ft_u_nb_to_a(nb, base);
	i = -1;
	if (print->arg->type == 'X')
		while (print->last_type[++i])
			print->last_type[i] = ft_toupper(print->last_type[i]);
	if (print->last_type[0] == '0' && (print->arg->type == 'x'
	|| print->arg->type == 'X'))
		print->arg->htag = 0;
	paste_int_in_printf(print, print->last_type);
	return (0);
}
