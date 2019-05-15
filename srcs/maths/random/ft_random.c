/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:52:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/13 20:48:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

static void		ft_if_random(intmax_t min, intmax_t max, intmax_t *rando,
					size_t *len)
{
	if (*len == 0)
		*len = 151;
	else if (*len > 50000)
		*len = 50000;
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

intmax_t		ft_random(intmax_t min, intmax_t max, intmax_t ran, size_t len)
{
	int			mod;

	mod = 1;
	if (!max && !min)
		mod = 0;
	else if (max == min)
		max = min + 100;
	if (min > max)
		ft_swap(&min, &max, sizeof(min));
	max++;
	if (ran && len)
		ft_if_random(min, max, &ran, &len);
	else
	{
		if (!ran)
			ran = ft_seed_time(min, max);
		while (!len)
			len = ft_seed_time(min, max);
	}
	if (mod)
		return (ft_end_random(min, max, ran, len));
	else
		return (ft_end_n_random(ran, len));
}
