/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:46:25 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 12:46:31 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_exe.h"

double				cl(clock_t t)
{
	static double	last;
	double			m;

	m = ((double)(t - last)) / (CLOCKS_PER_SEC);
	last = ((double)(clock()));
	return (m);
}
