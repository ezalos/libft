/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:12:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/10/12 16:51:30 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_btree
{
	void			*content;
	size_t			content_size;
	struct s_btree	*child[2];
}					t_btree;

# define DIR 4

typedef	struct		s_tab
{
	struct s_tab	*dir[DIR];
	void			*content;
	size_t			content_size;
}					t_tab;

typedef	struct		s_gnl
{
	char			*save;
	char			*content;
	int				content_size;
	int				already_read;
	int				fd;
	int				end;
}					t_gnl;

typedef struct		s_progress
{
	char			*name;
	intmax_t		max;
	intmax_t		now;
	intmax_t		len;
	intmax_t		written;
}					t_progress;

#endif
