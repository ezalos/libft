/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_to_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:57:15 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/29 15:59:12 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_sum_to_nb(intmax_t nb)
{
	intmax_t	ans;
	int			neg;

	neg = 1;
	if (nb < 0)
	{
		nb = -nb;
		neg = -1;
	}
	ans = (nb + 1) * (nb / 2);
	if (nb % 2)
		ans += (nb / 2) + 1;
	ans *= neg;
	return (ans);
}
