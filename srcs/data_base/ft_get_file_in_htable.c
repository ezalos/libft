/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_in_htable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:13:33 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/08 18:58:03 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_file_in_htable(char *str)
{
	size_t	fd;
	int		i;
	char	*line;
	ssize_t	size;

	if (PROGRESS)
		size = ft_get_size_file(str) / 5;
	if (!(fd = open(str, O_RDONLY)))
		return (-1);
	i = -1;
	while (get_next_line(fd, &line) > 0)
	{
		if (PROGRESS)
			ft_progress(__func__, ++i, size);
		ft_store_htable((void*)line, ft_strlen(line), &ft_hfunc);
	}
	close(fd);
	return (i + 1);
}
