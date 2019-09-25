/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 23:30:39 by ldevelle          #+#    #+#             */
/*   Updated: 2019/09/25 14:23:52 by ldevelle         ###   ########.fr       */
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
	int			i;

	i = 0;
	*size = 0;
	if (!(dest = ft_strnew(0)))
		return (NULL);
	while ((ret = read(fd, buff, BUFF_READ)) > 0)
	{
		if (buff[0] == '\0')
			return (NULL);
		*size += ret;
		if (ret == -1 || !(dest = ft_strrealloc(dest, *size)))
			return (NULL);
		buff[ret] = '\0';
		dest = ft_strcat(dest, buff);
		i++;
		if (*size >= 500000)
			break ;
	}
	return (dest);
}
