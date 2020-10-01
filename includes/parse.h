/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:57:06 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/30 15:41:34 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define MAX_ARGS		100
# define ARG_OPTION_CHARACTER		'-'

# define ARG_PROGRAM	1
# define ARG_OPTION		2
# define ARG_ARGUMENT	3
# define ARG_UNKNOWN	0

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
	//should be in the order they have been found
	//			from 0 elems to ac elems
	//can be :
	//			linked list
	//		->	pointer to first relevant av and relevant number ?
}				t_argument;


typedef	struct	s_parse
{
	char		*prog;//av[0]
	char		*name;
	char		*help;
	int			ac;
	int			end_options;
	char		**av;
	char		*use;// which av have been treated ?
	//args DS should be:
	//					expandable
	//					able to retrieve from name quickly
	//	can be	->	red black tree
	//				Htable
	//				dynamic array
	t_argument	args[MAX_ARGS];
	t_argument	*def;
	int			nb_args;
	int			nb_opts;
}				t_parse;

#endif
