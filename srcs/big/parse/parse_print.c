/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:51:10 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 11:51:13 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
