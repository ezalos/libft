/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_random.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:52:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 12:25:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_if_random(intmax_t min, intmax_t max, intmax_t *rando,
					size_t *len)
{
	if (*len > 50000)
		*len = *len % 50000;
	if (*len == 0)
		*len = 151;
	if (*rando == 0)
		*rando = ft_power(min, max);
}

static intmax_t	ft_10digits_prime(intmax_t nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb % 10 == 0)
		return (5915587277);
	else if (nb % 10 == 1)
		return (1500450271);
	else if (nb % 10 == 2)
		return (3267000013);
	else if (nb % 10 == 3)
		return (5754853343);
	else if (nb % 10 == 4)
		return (4093082899);
	else if (nb % 10 == 5)
		return (9576890767);
	else if (nb % 10 == 6)
		return (3628273133);
	else if (nb % 10 == 7)
		return (2860486313);
	else if (nb % 10 == 8)
		return (5463458053);
	else
		return (3367900313);
}

static intmax_t	ft_end_random(intmax_t min, intmax_t max, intmax_t rando,
					size_t len)
{
	while ((int)--len > 0)
		rando = (ft_10digits_prime(len * rando) * (rando % 100000))
				+ ft_10digits_prime((len + rando) * (rando % len));
	rando = (ft_10digits_prime(rando / 7) * rando)
			+ ft_10digits_prime((rando / 3) * (rando));
	if (rando < 0)
		rando = -rando;
	rando = rando % (max - min);
	if (min < 0)
		rando = rando + min;
	else
		rando = rando - min;
	return (rando);
}

static intmax_t	ft_end_n_random(intmax_t rando, size_t len)
{
	while ((int)--len > 0)
		rando = (ft_10digits_prime(len * rando) * (rando % 100000))
				+ ft_10digits_prime((len + rando) * (rando % len));
	rando = (ft_10digits_prime(rando / 7) * rando)
			+ ft_10digits_prime((rando / 3) * (rando));
	return (rando);
}

intmax_t		ft_simple_random(intmax_t mn, intmax_t mx, intmax_t r, size_t l)
{
	int			mod;

	mod = 1;
	if (mx == 0 && mn == 0)
		mod = 0;
	else if (mx - mn == 0)
		mx = mn + 100;
	if (mn > mx)
		ft_swap(&mn, &mx, sizeof(mn));
	mx++;
	if (r && l)
		ft_if_random(mn, mx, &r, &l);
	else if (!r || !l)
	{
		if (!r)
			r = ILLEGAL;
		if (!l)
			l = ILLEGAL % 50000;
	}
	if (mod)
		return (ft_end_random(mn, mx, r, l));
	else
		return (ft_end_n_random(r, l));
}
