/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:52:19 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 12:49:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_exe.h"

/*
** time_exe(__func__);
** print_time();
*/

/*
** void			print_time_struct(t_time *g)
** {
** 	printf(_RED"\t\tAdress:\t\t%p\n", (void *)g);
** 	printf(_CYAN "\t%s" _RESET, g->name);
** 	ft_puttab(g->name, 4);
** 	printf(_CYAN "Time: %f s.\n" _RESET, ((double)g->t));
** 	printf("\t\tNEXT:\t\t%p\n\n" _RESET, (void*)g->next);
** }
*/

static t_time		*time_link_creation(const char *s, double t)
{
	t_time			*timee;

	if (!(timee = (t_time*)P_MALLOC(sizeof(t_time))))
		return (NULL);
	timee->name = ft_strdup((const char*)s);
	timee->t = t;
	timee->nb_call = 1;
	timee->next = NULL;
	return (timee);
}

static t_time		*time_exceptions(t_time **timee, char **last,
	const char *s, double t)
{
	if (s == NULL)
	{
		cl(clock());
		return (NULL);
	}
	else
	{
		*last = ft_strdup((const char*)s);
		*timee = time_link_creation(s, t);
		cl(clock());
		return (*timee);
	}
}

static int			update_time(t_time *timee, const char *s, double t)
{
	if (!ft_strcmp(s, timee->name))
	{
		timee->t = timee->t + t;
		timee->nb_call++;
		return (1);
	}
	return (0);
}

static t_time		*update_last(t_time *timee, char **last, const char *s)
{
	char				*tmp;

	if (ft_strcmp(s, *last))
	{
		tmp = (char*)*last;
		*last = ft_strdup((const char*)s);
		free(tmp);
	}
	cl(clock());
	return (timee);
}

t_time				*time_exe(const char *s)
{
	static t_time		*timee;
	static char			*last;
	t_time				*tmp;
	double				t;

	if (!TIME_RECORD)
		return (NULL);
	t = cl(clock());
	if (s == NULL || timee == NULL || last == NULL)
		return (time_exceptions(&timee, &last, s, t));
	if (update_time(timee, (const char*)last, t))
		return (update_last(timee, &last, s));
	tmp = timee;
	while (tmp->next != NULL)
	{
		if (update_time(tmp, (const char*)last, t))
			return (update_last(timee, &last, s));
		tmp = tmp->next;
	}
	if (update_time(tmp, (const char*)last, t))
		return (update_last(timee, &last, s));
	tmp->next = time_link_creation((const char*)last, t);
	return (update_last(timee, &last, s));
}
