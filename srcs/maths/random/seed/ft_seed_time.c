/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seed_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:28:23 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/29 15:42:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

intmax_t	ft_seed_time(intmax_t min, intmax_t max)
{
	intmax_t	ans;

	ans = (intmax_t)clock();
	ans = ft_nb_in_range(min, max, ans);
	return (ans);
}
