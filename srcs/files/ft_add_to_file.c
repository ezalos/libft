/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:36:25 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/10 22:36:32 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_add_to_file(char *name, char *data)
{
	int				fd;

	fd = open(name, O_CREAT|O_RDWR|O_APPEND, S_IRWXU|S_IRWXG|S_IRWXO);
	ft_putendl_fd(data, fd);
	close(fd);
}
