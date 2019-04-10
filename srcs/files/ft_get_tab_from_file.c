/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tab_from_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:44:03 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/10 22:46:42 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_tab_from_file(char *str, int **tab, int lines)
{
	size_t	fd;
	int		i;
	char	*line;

	if (!(fd = open(str, O_RDONLY)))
		return (-1);
	if (!(*tab = ft_memalloc(sizeof(int) * lines)))
		return (-1);
	i = -1;
	while (get_next_line(fd, &line) > 0 && i < lines)
		(*tab)[++i] = ft_atoi(line);
	close(fd);
	return (i + 1);
}
