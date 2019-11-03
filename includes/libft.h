/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:15:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/11/03 07:42:35 by gtaja            ###   ########.fr       */
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
# include "./vector.h"
# include "./define.h"

# ifndef ILLEGAL
#  include <time.h>
#  define ILLEGAL clock()
# endif

# include "./auto.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 	65536
# endif
# define BUFF_READ 		4194304 / 32
# define SIZE_HTABLE	5000

# ifndef P_MALLOC
#  define P_MALLOC malloco
# endif

# ifndef NREE
#  define NREE 0
# endif
# ifndef PROGRESS
#  define PROGRESS 1
# endif

# ifndef TIME_RECORD
#  define TIME_RECORD	1
# endif

# define DEBUG_FUNC		ft_printf("%s\n", __func__)
# define DEBUG_INT(ret)	ft_printf("%s: %d\n", __func__, ret)
# define DEBUG_COLOR	ft_printf("%~{?}%s\n", __func__)

/*
** # define ILLEGAL (intmax_t)&rando
*/

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
