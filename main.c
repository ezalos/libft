/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:36:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/13 20:49:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

ssize_t		ft_hfuncoo(void *data, size_t size)
{
	int		temp;

	(void)size;
	ft_memmove(&temp, data, size);
	if (temp > SIZE_HTABLE || temp < 0)
		return (-1);
	return (temp);
}

int		main(int ac, char **av)
{
	int		i;

	if (ac != 2)
		return (0);
	i = 0;
	while (++i < SIZE_HTABLE)
		ft_store_htable((void*)ft_random(0, 5000, 0, 0), sizeof(int), &ft_hfuncoo);

	// ft_get_file_in_htable(av[1]);
	i = 0;
	while (!ft_access_htable(i))
		i++;
	i--;
	_CLEAR_SCREEN;
	ft_place_cursor(0, 0);
	while (++i < SIZE_HTABLE)
		if (ft_access_htable(i))
			ft_printf("[%*d] %~{155;255;155}%*d%~{}\n",
			ft_nb_len(SIZE_HTABLE, 10), i, ft_access_htable(i) / 3, ft_access_htable(i));
		else
			ft_printf("[%*d]%~{255;155;155}0%~{}\n", ft_nb_len(SIZE_HTABLE, 10), i);
	ft_clean_garbage();
	return (0);
}
