/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seed_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:16:00 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/29 16:28:17 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_seed_gnl(intmax_t min, intmax_t max)
{
	char		*rand;
	int			box[4];

	box[0] = open("/dev/random", O_RDONLY);
	if (!(get_next_line(box[0], &rand)))
		return (0);
	box[2] = ft_strnlen(rand, 5000);
	box[1] = -1;
	while (++box[1] < box[2])
		box[3] += rand[box[1]] * box[2];
	close(box[0]);
	ft_strdel(&rand);
	box[3] = ft_nb_in_range(min, max, box[3]);
	return (box[3]);
}
