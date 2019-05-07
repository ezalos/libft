/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:51:05 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 19:33:00 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_EXE_H
# define TIME_EXE_H

# include "libft.h"
# include <time.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct			s_time
{
	double				t;
	int					nb_call;
	char				*name;
	struct s_time		*next;
}						t_time;

/*
** main
*/
t_time					*time_exe(const char *s);
void					print_time(void);
double					cl(clock_t t);

#endif
