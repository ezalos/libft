/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:12:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 11:13:09 by ldevelle         ###   ########.fr       */
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

# define DIR 4

typedef	struct		s_tab
{
	struct s_tab	*dir[DIR];
	void			*content;
	size_t			content_size;
}					t_tab;

typedef struct		s_progress
{
	char			*name;
	intmax_t		max;
	intmax_t		now;
	intmax_t		len;
	intmax_t		written;
}					t_progress;

#endif
