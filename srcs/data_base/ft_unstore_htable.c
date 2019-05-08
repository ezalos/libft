/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unstore_htable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:09:52 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/08 17:10:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_unstore_htable(void *data, size_t size,
	ssize_t (*hf)(void *, size_t))
{
	ssize_t		temp;

	if ((temp = hf(data, size)) == -1 || (*ft_htable_mem())[temp] == 0)
		return (-1);
	else
		return ((*ft_htable_mem())[temp]--);
}
