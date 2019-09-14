/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:36:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/09/11 18:53:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		main(int ac, char **av)
{
	int		goal = 10000000;
	int		i;
	void	*trash;

	if (ac != 2)
		return (0);
	(void)av;
	time_exe("malloc");
	i = 0;
	while (++i < goal)
		trash = malloc(9);
	time_exe("LOUIS");
	i = 0;
	while (++i < goal)
		trash = nalloc(9);
	// time_exe("memalloc");
	// i = 0;
	// while (++i < goal)
	// 	trash = ft_memalloc(9);
	print_time();
	return (0);
}
