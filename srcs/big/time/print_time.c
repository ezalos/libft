/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:42:48 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 12:43:35 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_exe.h"

/*
** time_exe(__func__);
** print_time();
*/

t_time			*list_exchange(t_time **timee)
{
	t_time	*first;
	t_time	*middle;
	t_time	*last;

	if (*timee == NULL)
		return (NULL);
	first = (*timee);
	middle = (*timee)->next;
	last = (*timee)->next->next;
	(*timee) = middle;
	(*timee)->next = first;
	(*timee)->next->next = last;
	return (*timee);
}

void			sort_list(t_time **timee)
{
	t_time	*tmp;
	t_time	*late;

	tmp = *timee;
	late = NULL;
	while (tmp->next != NULL)
	{
		if (tmp->t > tmp->next->t && late != NULL)
		{
			list_exchange(&(late->next));
			tmp = *timee;
			late = NULL;
		}
		tmp = tmp->next;
		if (late == NULL)
			late = *timee;
		else
			late = late->next;
	}
}

void			print_elements(t_time *tmp, double total, int tab)
{
	tab = tab * 4;
	printf("\t________________________________________________________\n");
	while (tmp)
	{
		if (total != 0)
		{
			printf("\t");
			if ((int)(((tmp->t) / total) * 100) / 10 < 1)
				printf(" ");
			printf(_YELLOW"%d%%"_RESET, (int)(((tmp->t) * 100 / total) + 0.5));
		}
		else
			printf("\t");
		printf(_RED "\t%-*s" _RESET, tab, tmp->name);
		printf(_MAGENTA "%f s\n" _RESET, ((double)tmp->t));
		printf(_GREEN "\tn:%-*d" _RESET, tab, tmp->nb_call);
		printf(_CYAN "Rt:\t%f s/n\n" _RESET, (double)(tmp->t / tmp->nb_call));
		printf("\t________________________________________________________\n");
		tmp = tmp->next;
	}
}

void			print_total(double total)
{
	int			min;

	if (total <= 1)
		printf(_CYAN "\n\t\tProgram took " _GREEN "%f"
		_CYAN " seconds to execute\n\n" _RESET, (double)total);
	else if (total < 60)
		printf(_CYAN "\n\t\tProgram took " _YELLOW "%f"
		_CYAN " seconds to execute\n\n" _RESET, (double)total);
	else
	{
		min = (int)total / 60;
		total = total - (min * 60);
		printf(_CYAN "\n\t\tProgram took\t" _RED "%d"
		_CYAN " minutes " _RED "\n\t\t\t\t%f" _CYAN " seconds to execute\n\n"
		_RESET, min, total);
	}
	_C_RESET;
}

void			print_time(void)
{
	t_time		*timee;
	t_time		*tmp;
	double		total;
	int			max_length;

	if (!TIME_RECORD)
		return ;
	timee = time_exe(__func__);
	total = 0;
	tmp = timee;
	max_length = 0;
	while (tmp)
	{
		total += tmp->t;
		if (max_length < (int)ft_strlen(tmp->name))
			max_length = (ft_strlen(tmp->name) / 4);
		tmp = tmp->next;
	}
	tmp = timee;
	if (!(timee = (t_time*)cnalloc(NULL, sizeof(t_time))))
		return ;
	timee->next = tmp;
	sort_list(&timee);
	print_elements(timee->next, total, max_length + 8);
	print_total(total);
}
