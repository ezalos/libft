/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seed_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:02:15 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/29 17:35:24 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_seed_adress(intmax_t min, intmax_t max)
{
	int		ans;

	ans = ft_nb_in_range(min, max, (intmax_t)&min + (intmax_t)&max);
	return (ans);
}
