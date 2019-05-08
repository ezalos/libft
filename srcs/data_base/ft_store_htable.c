/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_htable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:09:14 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/08 17:14:42 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_store_htable(void *data, size_t size,
	ssize_t (*hf)(void *, size_t))
{
	ssize_t		temp;

	if ((temp = hf(data, size)) == -1)
		return (-1);
	else
		return ((*ft_htable_mem())[temp] += 1);
}
