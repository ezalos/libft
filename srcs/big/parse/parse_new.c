/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:52:58 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 11:53:01 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_parse	*parse_new(char *name, char *help)
{
	t_parse	*arg;

	arg = parse_mem();
	ft_bzero(arg, sizeof(t_parse));
	arg->name = name;
	arg->help = help;
	parse_add_option('h', "help", "Display usage");
	return (arg);
}
