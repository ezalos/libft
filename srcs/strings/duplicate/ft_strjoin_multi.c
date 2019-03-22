/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:14:54 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 14:11:43 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		transfer_tabtab_to_tab(char *dest, char **srcs, size_t *nb)
{
	int			i;
	int			j;
	int			k;

	k = -1;
	i = -1;
	while (++i < (int)*nb)
	{
		j = -1;
		while (srcs[i][++j])
			dest[++k] = srcs[i][j];
		ft_memdel((void**)&srcs[i]);
	}
	return (1);
}

static int		get_args_in_tab(char **srcs, va_list ap, size_t *nb,
				size_t *size_total)
{
	int			i;

	i = -1;
	while (++i < (int)*nb)
	{
		srcs[i] = (char*)va_arg(ap, char*);
		if (!srcs[i])
		{
			if (1)
			{
				i--;
				nb--;
			}
			else
			{
				while (--i)
					ft_memdel((void**)&srcs[i]);
				ft_memdel((void**)&srcs);
				return (0);
			}
		}
		else
			*size_total += ft_strlen(srcs[i]);
	}
	return (1);
}

char			*ft_strjoin_multi(size_t nb, ...)
{
	va_list		ap;
	size_t		size_total;
	char		**srcs;
	char		*dest;

	if (nb < 2)
		return (NULL);
	if (!(srcs = (char**)P_MALLOC(sizeof(char*) * nb)))
		return (NULL);
	va_start(ap, nb);
	size_total = 0;
	if (!get_args_in_tab(srcs, ap, &nb, &size_total))
		return (NULL);
	va_end(ap);
	if (!(dest = ft_strnew(size_total)))
	{
		while (--nb)
			ft_memdel((void**)&srcs[nb]);
		ft_memdel((void**)&srcs);
		return (NULL);
	}
	transfer_tabtab_to_tab(dest, srcs, &nb);
	dest[size_total] = 0;
	ft_memdel((void**)&srcs);
	return (dest);
}
