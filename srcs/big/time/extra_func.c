/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:46:25 by ldevelle          #+#    #+#             */
/*   Updated: 2019/10/22 09:27:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double				cl(clock_t t)
{
	static double	last;
	double			m;

	m = ((double)(t - last)) / (CLOCKS_PER_SEC);
	last = ((double)(clock()));
	return (m);
}
