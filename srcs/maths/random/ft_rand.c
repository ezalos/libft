/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:52:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/09/14 18:58:54 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static intmax_t	ft_end_random(intmax_t max, intmax_t rando, size_t len)
{
	while ((int)--len > 0)
		rando += (ft_10digits_prime(len * rando) * (rando))
				+ ft_10digits_prime((len + rando) * (rando % len));
	if (rando < 0)
		rando = -rando;
	return (rando % max);
}

static intmax_t	ft_end_n_random(intmax_t rando, size_t len)
{
	while ((int)--len > 0)
		rando += (ft_10digits_prime(len * rando) * (rando))
				+ ft_10digits_prime((len + rando) * (rando % len));
	return (rando);
}

intmax_t		ft_rand(intmax_t max, intmax_t seed)
{
	size_t		len;

	len = 32;
	if (max > 0)
		return (ft_end_random(max, seed, len));
	else
		return (ft_end_n_random(seed, len));
}
