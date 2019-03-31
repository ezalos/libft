/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:36:08 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/30 16:32:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int ac, char **av)
{
	// char			*line;
	size_t			fd;
	intmax_t		i;
	intmax_t		av_one;
	intmax_t		av_two;

	if (ac != 2)
		return (0);
	(void)av;
	av_one = INTMAX_MIN;
	av_two = INTMAX_MAX;
	i = 0;
	fd = open(av[1], O_RDONLY);
	while (1){
		ft_printf("%~{!}", ft_random(-10, 10, 0, 0));
	}
	return (0);
}
