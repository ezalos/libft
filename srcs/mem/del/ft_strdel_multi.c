/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_multi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:14:54 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/07 14:15:51 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel_multi(size_t nb, ...)
{
	va_list		ap;
	int			i;
	char		**as;

	if (nb != 0)
	{
		va_start(ap, nb);
		i = -1;
		while (++i < (int)nb)
		{
			as = va_arg(ap, char**);
			ft_strdel(as);
		}
		va_end(ap);
	}
}
