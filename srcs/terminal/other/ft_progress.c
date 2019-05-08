/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_progress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 18:24:18 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/08 15:31:35 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_is_new_progress(t_progress *tim, const char *name, intmax_t max)
{
	int			i;

	if (tim->name)
		ft_strdel(&tim->name);
	ft_bzero(tim, sizeof(*tim));
	tim->len = 40;
	tim->name = ft_strdup(name);
	tim->max = max;
	ft_printf("\n%~{150;150;255}Progress of %~{255;100;100}%s%~{}\n",
	tim->name);
	i = -1;
	ft_printf("\t[");
	_CURSOR_SAVE;
	while (++i < tim->len)
		ft_printf(" ");
	ft_printf("]");
}

static void	ft_let_print(t_progress *tim, intmax_t now, intmax_t max)
{
	int			i;

	_CURSOR_LOAD;
	i = -1;
	while (++i + ((tim->now * tim->len) / tim->max) < (now * tim->len) / max
	&& tim->written <= tim->len)
	{
		ft_printf("%~{100;255;100}-%~{}");
		tim->written++;
	}
	_CURSOR_SAVE;
	tim->now = now;
	if (max == now)
	{
		while (tim->written < tim->len)
		{
			ft_printf("%~{100;255;100}-%~{}");
			tim->written++;
		}
		ft_printf("\n");
	}
}

void		ft_progress(const char *name, intmax_t now, intmax_t max)
{
	static t_progress	tim;

	if (!max)
		max = 1;
	if (tim.max != max
	&& (!tim.name || ft_strcmp(name, tim.name)))
		ft_is_new_progress(&tim, name, max);
	if ((tim.now * tim.len) / tim.max < (now * tim.len) / max)
		ft_let_print(&tim, now, max);
	tim.max = max;
}
