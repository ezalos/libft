/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:53:17 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 11:53:25 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_argument	*parse_get_opt(char opt, int empty)
{
	int		i;
	t_parse	*arg;

	arg = parse_mem();
	i = -1;
	while (++i < arg->nb_args)
		if (opt == arg->args[i].option)
			if (arg->args[i].raw || empty)
				return (&arg->args[i]);
	return (NULL);
}

t_argument	*parse_get_arg(char *name, int empty)
{
	int		i;
	t_parse	*arg;

	arg = parse_mem();
	i = -1;
	while (++i < arg->nb_args)
		if (!ft_strcmp(name, arg->args[i].name))
			if (arg->args[i].raw || empty)
				return (&arg->args[i]);
	return (NULL);
}

t_argument	*parse_get(char *name)
{
	return (parse_get_arg(name, FALSE));
}
