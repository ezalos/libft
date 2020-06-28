/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 13:22:18 by ezalos            #+#    #+#             */
/*   Updated: 2020/06/28 14:02:12 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


t_parse	*parse_mem(void)
{
	static t_parse	args;

	return (&args);
}

void	parse_print_arg(t_argument *arg)
{
	int		i;
	ft_printf("\tname:    %s\n", arg->name);
	ft_printf("\thelp:    %s\n", arg->help);
	ft_printf("\targ nb:  %d\n", arg->arg_nb);
	ft_printf("\traw :    %p\n", arg->raw);
	ft_printf("\n\traw len: %d\n", arg->len);
	ft_printf("\targs:    ");
	i = -1;
	while (++i < arg->len)
		ft_printf("%s ", arg->raw[i]);
	ft_printf("\n");
}

void	parse_print(void)
{
	t_parse	*arg;
	int		i;

	arg = parse_mem();
	ft_printf("prog:   %s\n", arg->prog);
	ft_printf("name:   %s\n", arg->name);
	ft_printf("help:   %s\n", arg->help);
	ft_printf("ac:     %d\n", arg->ac);
	ft_printf("nb_arg: %d\n", arg->nb_args);
	ft_printf("use:\n\t");
	i = -1;
	while (++i < arg->ac)
		ft_printf("%d %s\t", arg->use[i], arg->av[i]);
	ft_printf("\n");
	i = -1;
	while (++i < arg->nb_args)
	{
		ft_printf("\nARG %d\n", i);
		parse_print_arg(&arg->args[i]);
	}
}

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

t_parse	*parse_new(char *name, char *help)
{
	t_parse	*arg;
	arg = parse_mem();

	ft_bzero(arg, sizeof(t_parse));
	arg->name = name;
	arg->help = help;
	parse_add_option('h', "help",		"Display usage");
	return (arg);
}

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

int		parse_args_save(int arg_place, t_argument *argument, int arg_type)
{
	t_parse	*arg;

	arg = parse_mem();
	argument->raw = &arg->av[arg_place];
	argument->len = arg->ac - arg_place;
	argument->len = 1;
	arg->use[arg_place] = arg_type;
	return (1);
}

int		parse_args(int ac, char **av)
{
	int			i;
	int			o;
	t_parse		*arg;
	t_argument	*argument;

	arg = parse_mem();
	i = 0;
	arg->ac = ac;
	arg->av = av;
	arg->use = ft_memalloc(ac + 1);
	arg->prog = av[i];
	arg->use[i] = ARG_PROGRAM;
	while (++i < ac)
	{
		if (av[i][0] == ARG_OPTION_CHARACTER && arg->end_options == 0)
		{
			if (av[i][1] == ARG_OPTION_CHARACTER)
			{
				if (av[i][2] == '\0')
					arg->end_options = i;
				else
				{
					if ((argument = parse_get_arg(av[i] + 2 /*account for '--' */, TRUE)))
						parse_args_save(i, argument, ARG_OPTION);
					else
					{
						ft_printf("Error: '%s' is not a recognized option\n", av[i]);
						ft_printf("Please refer to usage: %s -h\n", arg->prog);
						return (FAILURE);
					}
				}
			}
			else
			{
				o = 0;
				while (av[i][++o])
					if ((argument = parse_get_opt(av[i][o], TRUE)))
						parse_args_save(i, argument, ARG_OPTION);
					else
					{
						ft_printf("Error: '%s' -> '%c' is not a recognized option\n", av[i], av[i][o]);
						ft_printf("Please refer to usage: %s -h\n", arg->prog);
						return (FAILURE);
					}
			}
		}
		else
		{
			//need to be saved in the right argument
			if (arg->def->raw == NULL)
				parse_args_save(i, arg->def, ARG_ARGUMENT);
			else
			{
				ft_printf("Error: '%s'\n", av[i]);
				ft_printf("       '%s' is already the default argument\n", arg->def->raw[0]);
				ft_printf("Please refer to usage: %s -h\n", arg->prog);

			}
		}
	}
	return (SUCCESS);
}

int		parse_usage(void)
{
	int		i;
	t_parse	*arg;

	arg = parse_mem();
	ft_printf("Usage: ");
	ft_printf("%s ", arg->prog);
	i = -1;
	while (++i < arg->nb_args)
	{
		if (arg->args[i].option)
			ft_printf("[-%c OR --%s] ", arg->args[i].option,arg->args[i].name);
		else
		{
			ft_printf("[--] ");
			ft_printf("[%s] ", arg->args[i].name);
		}
	}
	ft_printf("\n\n");
	ft_printf("%s:\n\t%s\n\n", arg->name, arg->help);
	ft_printf("Options:\n");
	i = -1;
	while (++i < arg->nb_args)
		//if (arg->args[i].option)
			ft_printf("\t%c \t%10s \t%s\n",arg->args[i].option, arg->args[i].name, arg->args[i].help);
	//	else
	//		ft_printf("\t%s \t%10s\n", arg->args[i].name, arg->args[i].help);
	ft_printf("\n");
	return (0);
}
