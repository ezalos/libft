/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:52:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/12 21:39:23 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	box[0] = int	fd;
**	box[1] = int	size;
**	box[2] = int	i;
**	box[3] = max - min;
*/

#include <stdio.h>

static void	ft_if_random(intmax_t min, intmax_t max, int *box_one, intmax_t *rando)
{
	*box_one = 151;
	if (*rando == 0)
		*rando = ft_power(min, max);
}

int		ft_random(intmax_t min, intmax_t max, intmax_t rando)
{
	char		*rand;
	long long	prime[2];
	int			box[4];

	prime[0] = 5915587277;
	prime[1] = 9576890767;
	box[3] = max - min;
	if (max - min == 0)
		max = min + 100;
	if (min > max)
		ft_swap(&min, &max, sizeof(min));
	if (-1 == (box[0] = open("/dev/random", O_RDONLY)))
		ft_if_random(min, max, &box[1], &rando);
	else
	{
		if (!(get_next_line(box[0], &rand)))
			return (0);
		box[1] = ft_strlen(rand);
		box[2] = -1;
		if (rando == 0)
			while (++box[2] < box[1])
				rando += rand[box[2]];
		close(box[0]);
		ft_strdel(&rand);
	}
	while (--box[1] > 0)
	{
		rando = (prime[0] * rando) + prime[1];
	}
	rando = (uintmax_t)(rando % (box[3]));
	if (min < 0)
		rando = rando + min;
	else
		rando = rando - min;
	return (rando);
}
