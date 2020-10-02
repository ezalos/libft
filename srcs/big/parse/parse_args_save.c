/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_save.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:55:50 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 11:55:53 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		parse_args_save(int arg_place, t_argument *argument, int arg_type)
{
	t_parse	*arg;

	arg = parse_mem();
	argument->raw = &arg->av[arg_place];
	argument->len = arg->ac - arg_place;
	argument->len = 1;
	argument->arg_place = arg_place;
	arg->use[arg_place] = arg_type;
	return (1);
}
