/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:57:06 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 12:29:03 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define MAX_ARGS					100
# define ARG_OPTION_CHARACTER		'-'

# define ARG_PROGRAM				1
# define ARG_OPTION					2
# define ARG_ARGUMENT				3
# define ARG_UNKNOWN				0

typedef	struct	s_argument
{
	char		option;
	const char	*name;
	const char	*help;
	int			len;
	int			position;
	int			arg_nb;
	int			arg_place;
	char		**raw;
}				t_argument;

typedef	struct	s_parse
{
	char		*prog;
	char		*name;
	char		*help;
	int			ac;
	int			end_options;
	char		**av;
	char		*use;
	t_argument	args[MAX_ARGS];
	t_argument	*def;
	int			nb_args;
	int			nb_opts;
}				t_parse;

#endif
