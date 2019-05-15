/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:43:37 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/15 14:20:42 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_get_size_file(char *str)
{
	int			fd;
	ssize_t		r_v;
	ssize_t		red;
	char		line[BUFF_SIZE + 1];

	if (!(fd = open(str, O_RDONLY)))
		return (-1);
	r_v = 0;
	while ((red = read(fd, line, BUFF_SIZE)) > 0)
		r_v += red;
	r_v += red;
	close(fd);
	return (r_v);
}
