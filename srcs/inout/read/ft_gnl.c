/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:03:34 by ldevelle          #+#    #+#             */
/*   Updated: 2019/09/14 18:59:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		update_gnl_struct(t_gnl *gnl, char **line)
{
	char	*tmp;
	int		next_break;

	if ((tmp = ft_strchr(gnl->content, (int)'\n')))
		next_break = (tmp - gnl->content);
	else
		next_break = ft_strlen(gnl->content);
	*line = ft_memalloc(next_break + 1);
	ft_memmove(*line, gnl->content, next_break);
	(*line)[next_break] = '\0';
	gnl->content += next_break + 1;
	gnl->already_read += next_break + 1;
	gnl->content_size -= next_break + 1;
	if (gnl->content_size <= 0)
	{
		gnl->end = 0;
		ft_strdel(&gnl->content);
	}
	return (next_break);
}

int		get_line(t_gnl *gnl, char **line)
{
	if (gnl->end)
	{
		gnl->content = ft_read_file(gnl->fd, &gnl->content_size);
		if (!gnl->content_size)
		{
			ft_strdel(&gnl->content);
			return (0);
		}
		else
			gnl->end = 1;
	}
	if (!gnl->content
	&& !(gnl->content = ft_read_file(gnl->fd, &gnl->content_size)))
		return (-1);
	return (update_gnl_struct(gnl, line));
}

int		create_struct_for_fd(int fd, char **line, t_list *tmp)
{
	if (!(tmp->next = ft_lstnew(0, fd))
	|| !(tmp->next->content = ft_memalloc(sizeof(t_gnl))))
		return (-1);
	((t_gnl*)tmp->next->content)->fd = fd;
	return (get_line(tmp->next->content, line));
}

int		ft_gnl(const int fd, char **line)
{
	static	t_list	*gnl;
	t_list			*tmp;

	if (BUFF_SIZE < 1 || !line || fd > OPEN_MAX || fd < 0)
		return (-1);
	if (gnl == (t_list*)NULL)
	{
		if (!(gnl = ft_lstnew(0, fd))
		|| !(gnl->content = ft_memalloc(sizeof(t_gnl))))
			return (-1);
		((t_gnl*)gnl->content)->fd = fd;
		return (get_line(gnl->content, line));
	}
	tmp = gnl;
	if (((t_gnl*)tmp->content)->fd == fd)
		return (get_line(tmp->content, line));
	while (tmp->next != NULL)
	{
		if (((t_gnl*)tmp->next->content)->fd == fd)
			return (get_line(tmp->next->content, line));
		tmp = tmp->next;
	}
	return (create_struct_for_fd(fd, line, tmp));
}
