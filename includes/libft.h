/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:15:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/22 22:41:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include "./auto.h"

# define BUFF_SIZE 256

# ifndef P_MALLOC
#  define P_MALLOC nalloc
# endif

# ifndef NREE
#  define NREE 1
# endif

/*
** # define ILLEGAL (intmax_t)&rando
*/

# ifndef ILLEGAL
#  include <time.h>
#  define ILLEGAL clock()
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 100
# endif

/*
** # define LINUX
*/

# ifdef LINUX
#  define intmax_t long long
#  define uintmax_t unsigned long long
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 100
# endif

# define C_RED			write(1, "\x1b[31m", 5);
# define C_GREEN		write(1, "\x1b[32m", 5);
# define C_BLUE			write(1, "\x1b[34m", 5);
# define C_YELLOW		write(1, "\x1b[33m", 5);
# define C_BLUE			write(1, "\x1b[34m", 5);
# define C_MAGENTA		write(1, "\x1b[35m", 5);
# define C_CYAN			write(1, "\x1b[36m", 5);
# define C_RESET		write(1, "\x1b[0m", 5);
# define C_BROWN		write(1, "\x1b[38;2;238;205;163m", 19);
# define C_PINK			write(1, "\x1b[38;2;239;100;100m", 19);
# define C_PURPLE		write(1, "\x1b[38;2;101;78;163m", 18);
# define C_ORANGE		write(1, "\x1b[38;2;155;75;43m", 17);
# define C_TURQUOISE	write(1, "\x1b[38;2;68;140;121m", 18);
# define CURSOR_RESET	write(1, "\033[0;0H", 6);
# define CURSOR_LOAD	write(1, "\033[u", 3);
# define CURSOR_SAVE	write(1, "\033[s", 3);
# define CLEAR_SCREEN	write(1, "\033[2J", 4);


typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;



typedef	struct		s_tab
{
	struct s_tab	*dir[4];
	void			*content;
	size_t			content_size;
}					t_tab;

/*
**	dir[0] : up;
**	dir[1] : right;
**	dir[2] : down;
**	dir[3] : left;
*/

#endif
