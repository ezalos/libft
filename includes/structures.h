/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:12:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/11/01 15:28:53 by gtaja            ###   ########.fr       */
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

typedef struct		s_printfesse
{
	char				exist;
	char				background;
	int					red;
	int					green;
	int					blue;
	int					line;
	int					column;
	char				*base_in;
	char				*base_out;
	char				*rand_str;
	int					rand_nb;

}					t_printfesse;

typedef struct		s_arg
{
	int					zero_exist;
	char				type;
	int					minimum_width;
	int					ajust_left;
	char				space_filled;
	int					sign;
	int					htag;
	int					space;
	int					precision;
	int					precision_exist;
	int					modifier_h;
	int					modifier_l;
	int					modifier_ll;
}					t_arg;

typedef struct		s_printf
{
	t_list				*lst_to_print;
	const char			*format;
	char				*start_format;
	va_list				ap;
	char				*printf;
	char				*last_type;
	char				lets_print;
	int					i;
	size_t				size_all;
	size_t				fd;
	char				invisible;
	t_arg				arg[1];
	t_printfesse		bonus[1];
}					t_printf;

#endif
