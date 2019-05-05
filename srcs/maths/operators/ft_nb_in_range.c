/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_in_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:39:46 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 18:50:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

intmax_t	ft_nb_in_range(intmax_t min, intmax_t max, intmax_t nb)
{
	intmax_t	ans;
	uintmax_t	range;
	uintmax_t	u_nb;

	if (min == max)
		return (nb);
	if (min > max)
		ft_swap(&min, &max, sizeof(intmax_t));
	range = max - min;
	if (max >= 0 && min <= 0 && range != (UINTMAX_MAX))
		range++;
	u_nb = INTMAX_MIN + nb;
	ans = u_nb % range;
	ans = ans + min;
	return (ans);
}
