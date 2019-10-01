/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:06:54 by gtaja             #+#    #+#             */
/*   Updated: 2019/10/01 15:59:44 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*split_buffer(char *result, char *buffer, int len)
{
	char		*backslash;

	backslash = ft_strchr(result, '\n');
	if (backslash != NULL)
	{
		ft_strcpy(buffer, backslash + 1);
		*backslash = '\0';
	}
	else
		buffer[0] = '\0';
	if (len <= 0 && result[0] == '\0')
	{
		free(result);
		return (NULL);
	}
	else
		return (result);
}

int			gnl(int fd, char **line)
{
	static char	buffer[BUFF_SIZE + 1] = {0};
	char		*result;
	int			len;
	int			res_code;

	result = ft_strdup(buffer);
	len = 1;
	while (len > 0 && ft_strchr(result, '\n') == NULL)
	{
		len = read(fd, buffer, BUFF_SIZE);
		if (len <= 0)
			break ;
		buffer[len] = '\0';
		ft_strappend(&result, buffer);
	}
	res_code = len > 0 || result[0] != '\0';
	*line = split_buffer(result, buffer, len);
	return (res_code);
}
