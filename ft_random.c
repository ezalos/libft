/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:52:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/11 21:02:55 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		random(int min, int max)
{
	int			fd;
	int			size;
	char		*rand;
	long long	prime_a;
	long long	prime_b;
	long long	rando;

	prime_a = 5915587277;
	prime_b = 9576890767;

	fd = open("/dev/random", O_RDONLY);
	get_next_line(fd, rand);
	size = ft_strlen(rand);
	while (size > 0)
		rando = (prime_a * rando) + prime_b;
	close(fd);
}
