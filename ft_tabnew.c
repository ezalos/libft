/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:15:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/25 22:12:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int		main(int ac, char **av)
{
	t_tab	*tab;

	if (ac < 2)
		return (0);
	tab = ft_tabnew_dir(ft_atoi(av[1]), 2);
	ft_tab_square_it(tab, 2);
	ft_rgb_bcolor(20, 20, 20);
	ft_tabiter(tab, 2, &ft_tab_print_dir, 1);
	return (0);
}
