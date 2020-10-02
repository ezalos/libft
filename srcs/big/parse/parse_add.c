/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:52:39 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 11:52:45 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		parse_add_option(char opt, char *name, char *help)
{
	t_parse	*arg;

	arg = parse_mem();
	if (arg->nb_args < MAX_ARGS)
	{
		arg->args[arg->nb_args].option = opt;
		arg->args[arg->nb_args].name = name;
		arg->args[arg->nb_args].help = help;
		arg->args[arg->nb_args].arg_nb = arg->nb_args;
		arg->nb_args++;
		arg->nb_opts++;
	}
	return (arg->nb_args);
}

int		parse_add_arg(char *name, char *help)
{
	t_parse	*arg;

	arg = parse_mem();
	if (arg->nb_args < MAX_ARGS)
	{
		if (!arg->def)
			arg->def = &arg->args[arg->nb_args];
		arg->args[arg->nb_args].name = name;
		arg->args[arg->nb_args].help = help;
		arg->args[arg->nb_args].arg_nb = arg->nb_args;
		arg->nb_args++;
	}
	return (arg->nb_args);
}
