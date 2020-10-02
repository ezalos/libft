/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:54:16 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 12:00:52 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_usage_command(t_parse *arg)
{
	int		i;

	ft_printf("%s ", arg->prog);
	i = -1;
	while (++i < arg->nb_args)
	{
		if (arg->args[i].option)
			ft_printf("[-%c OR --%s] ", arg->args[i].option, arg->args[i].name);
		else
		{
			ft_printf("[--] ");
			ft_printf("[%s] ", arg->args[i].name);
		}
	}
	ft_printf("\n");
}

void	parse_usage_options(t_parse *arg)
{
	int		i;

	ft_printf("%s:\n\t%s\n\n", arg->name, arg->help);
	ft_printf("Options:\n");
	i = -1;
	while (++i < arg->nb_args)
		ft_printf("\t%c \t%10s \t%s\n", arg->args[i].option,
		arg->args[i].name, arg->args[i].help);
	ft_printf("\n");
}

int		parse_usage(void)
{
	t_parse	*arg;

	arg = parse_mem();
	ft_printf("Usage:\n\t");
	parse_usage_command(arg);
	ft_printf("\n");
	parse_usage_options(arg);
	return (0);
}
