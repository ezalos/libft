/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_progress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 18:24:18 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/30 18:32:03 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_is_new_progress(t_progress *progress, const char *name, intmax_t max)
{
	int			i;

	if (progress->name)
		ft_strdel(&progress->name);
	ft_bzero(progress, sizeof(t_progress));
	progress->len = 40;
	progress->name = ft_strdup(name);
	progress->max = max;
	ft_printf("\n%~{150;150;255}Progress of %~{255;100;100}%s%~{}\n", progress->name);
	i = -1;
	ft_printf("\t[");
	CURSOR_SAVE
	while (++i < progress->len)
		ft_printf(" ");
	ft_printf("]");
}

static void	ft_let_print(t_progress *progress, intmax_t now, intmax_t max)
{
	int			i;

	CURSOR_LOAD
	i = -1;
	while (++i + ((progress->now * progress->len) / progress->max) < (now * progress->len) / max
	&& progress->written <= progress->len)
	{
		ft_printf("%~{100;255;100}-%~{}");
		progress->written++;
	}
	CURSOR_SAVE
	progress->now = now;
	if (max == now)
	{
		while (progress->written < progress->len)
		{
			ft_printf("%~{100;255;100}-%~{}");
			progress->written++;
		}
		ft_printf("\n");
	}
}

void	ft_progress(const char *name, intmax_t now, intmax_t max)
{
	static t_progress	progress;

	if (!max)
		max = 1;
	if (progress.max != max && (!progress.name || ft_strcmp(name, progress.name)))
		ft_is_new_progress(&progress, name, max);
	if ((progress.now * progress.len) / progress.max < (now * progress.len) / max)
		ft_let_print(&progress, now, max);
	progress.max = max;
}
