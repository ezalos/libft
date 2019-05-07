/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:15:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 12:33:53 by ldevelle         ###   ########.fr       */
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
# include "./time_exe.h"
# include "./structures.h"
# include "./terminal_defines.h"

# ifndef ILLEGAL
#  include <time.h>
#  define ILLEGAL clock()
# endif

# include "./auto.h"

# define BUFF_SIZE 256

# ifndef P_MALLOC
#  define P_MALLOC nalloc
# endif

# ifndef NREE
#  define NREE 1
# endif

# ifndef TIME_RECORD
#  define TIME_RECORD	0
# endif

/*
** # define ILLEGAL (intmax_t)&rando
*/

# ifndef OPEN_MAX
#  define OPEN_MAX 100
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 100
# endif

/*
**	dir[0] : up;
**	dir[1] : right;
**	dir[2] : down;
**	dir[3] : left;
*/

#endif
