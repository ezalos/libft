/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:12:38 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/08 17:15:24 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_hfunc(void *data, size_t size)
{
	intmax_t		temp;

	(void)size;
	temp = ft_atoi(data);
	if (temp > SIZE_HTABLE || temp < 0)
		return (-1);
	return (temp);
}
