/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 23:30:39 by ldevelle          #+#    #+#             */
/*   Updated: 2019/11/01 15:30:31 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** char		*ft_read_file_tmp(int fd, int *size)
** {
** 	char	buff[BUFF_READ + 1];
** 	char	*dest;
** 	int		ret;
** 	int		i;
**
** 	i = 0;
** 	*size = 0;
** 	if (!(dest = ft_strnew(0)))
** 		return (NULL);
** 	while ((ret = read(fd, buff, BUFF_READ)) > 0)
** 	{
** 		*size += ret;
** 		if (ret == -1 || !(dest = ft_strrealloc(dest, *size)))
** 			return (NULL);
** 		buff[ret] = '\0';
** 		dest = ft_strcat(dest, buff);
** 		i++;
** 	}
** 	return (dest);
** }
*/

char		*ft_read_file(int fd, int *size)
{
	char		buff[BUFF_READ + 1];
	char		*dest;
	int			ret;

	*size = 0;
	dest = NULL;
	ft_bzero(buff, BUFF_READ + 1);
	while ((ret = read(fd, buff, BUFF_READ)) > 0)
	{
		buff[ret] = '\0';
		*size += ret;
		if (!(dest = ft_strrealloc(dest, *size + 1)))
			return (NULL);
		dest = ft_memmove(dest + (*size - ret), buff, ret);
		ft_bzero(buff, BUFF_READ + 1);
	}
	return (dest);
}
