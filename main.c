/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:36:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/07/02 18:40:15 by ldevelle         ###   ########.fr       */
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
	(void)av;
	ft_printf("Hello: %f\n", 14.3);
	return (0);
}
