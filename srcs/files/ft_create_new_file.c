/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:38:26 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 18:47:46 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_create_new_file(char *str)
{
	int		fd;
	int		i;
	char	*name;
	char	*num;

	if (!(name = ft_strdup(str)))
		return (-1);
	fd = -1;
	num = NULL;
	i = -1;
	while (++i || fd == -1)
		if (-1 != (fd = open(name, O_CREAT | O_EXCL | O_RDWR,
			S_IRWXU | S_IRWXG | S_IRWXO)))
			break ;
		else
		{
			ft_strdel_multi(2, &name, &num);
			if (!(num = ft_nb_to_a(i, 0)))
				return (-1);
			if (!(name = ft_strjoin_multi(3, str, "_", num)))
				return (-1);
		}
	ft_strdel(&name);
	ft_strdel(&num);
	return (fd);
}
