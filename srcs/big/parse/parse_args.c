/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 13:22:18 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 12:24:17 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_args_init(int ac, char **av)
{
	t_parse		*arg;

	arg = parse_mem();
	arg->ac = ac;
	arg->av = av;
	arg->use = ft_memalloc(ac + 1);
	arg->prog = av[0];
	arg->use[0] = ARG_PROGRAM;
}

int		parse_opts_double_dash(int index, char *av_arg)
{
	t_parse		*arg;
	t_argument	*argument;

	arg = parse_mem();
	if ((argument = parse_get_arg(av_arg + 2, TRUE)))
		parse_args_save(index, argument, ARG_OPTION);
	else
	{
		ft_printf("Error: '%s' is not a recognized option\n", av_arg);
		ft_printf("Please refer to usage: %s -h\n", arg->prog);
		return (FAILURE);
	}
	return (SUCCESS);
}

int		parse_opts_simple_dash(int index, char *av_arg)
{
	int			o;
	t_parse		*arg;
	t_argument	*argument;

	arg = parse_mem();
	o = 0;
	while (av_arg[++o])
		if ((argument = parse_get_opt(av_arg[o], TRUE)))
			parse_args_save(index, argument, ARG_OPTION);
		else
		{
			ft_printf("Error: '%s' -> '%c' is not a recognized option\n",
				av_arg, av_arg[o]);
			ft_printf("Please refer to usage: %s -h\n", arg->prog);
			return (FAILURE);
		}
	return (SUCCESS);
}

int		parse_args_unit(int index, char *av_arg)
{
	t_parse		*arg;

	arg = parse_mem();
	arg->end_options = TRUE;
	if (arg->def->raw == NULL)
		parse_args_save(index, arg->def, ARG_ARGUMENT);
	else if (0)
	{
		ft_printf("Error: '%s'\n", av_arg);
		ft_printf("       '%s' is already the default argument\n",
			arg->def->raw[0]);
		ft_printf("Please refer to usage: %s -h\n", arg->prog);
		return (FAILURE);
	}
	return (SUCCESS);
}

int		parse_args(int ac, char **av)
{
	t_parse		*arg;
	int			i;

	arg = parse_mem();
	parse_args_init(ac, av);
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == ARG_OPTION_CHARACTER && arg->end_options == FALSE)
		{
			if (av[i][1] == ARG_OPTION_CHARACTER)
			{
				if (av[i][2] == '\0')
					arg->end_options = TRUE;
				else if (parse_opts_double_dash(i, av[i]) == FAILURE)
					return (FAILURE);
			}
			else if (parse_opts_simple_dash(i, av[i]) == FAILURE)
				return (FAILURE);
		}
		else
			parse_args_unit(i, av[i]);
	}
	return (SUCCESS);
}
