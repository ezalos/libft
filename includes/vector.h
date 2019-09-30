/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:25:09 by amartino          #+#    #+#             */
/*   Updated: 2019/09/30 13:48:54 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define DEFAULT_VCT_SIZE 		64
# define DEFAULT_VCT_SCALE 		16
# define FIRST					1
# define SECOND					2
# define BOTH					3
# define NB_OF_APPLY_FUNC		3
# define NB_OF_TEST_FUNC		3
# define NB_TOTAL_OF_FUNC		NB_OF_APPLY_FUNC + NB_OF_TEST_FUNC

/*
*****************************************************************************
**	size  is the total lenght of str (including the '\0')
**	len	  is the number of characters of the string
**	scale is the number by which the string will be increase for each memory
**	      allocation
**
**	WARNING : 	you should NEVER dereference a vector directly. Use the
**				appropriate function or create it.
*****************************************************************************
*/

typedef struct	s_vector
{
	char		*str;
	size_t		size;
	size_t		len;
	size_t		scale;
}				t_vector;

typedef int		(*t_int_func)(char *);
typedef char	*(*t_char_ptr_func)(char *);

enum	e_apply
{
	UPCASE,
	LOWCASE,
	CAPITALIZE,
	IS_UPCASE,
	IS_LOWCASE,
	IS_BLANK,
	EMPTY,
};

/*
**********************
**  	 BASE	    **
**********************
*/
t_vector		*vct_new(size_t size);
t_vector		*vct_newstr(char *str);
size_t			vct_len(t_vector *vector);
int8_t			vct_increase_scale(t_vector *vector, size_t scale);
void			vct_bzero(t_vector *vector);
void			vct_del(t_vector **vector);
char			*vct_getstr(t_vector *vector);
char			vct_getchar_at(t_vector *vector, size_t index);

/*
**********************
**  	 ADD	    **
**********************
*/
int8_t			vct_addchar(t_vector *vector, char c);
int8_t			vct_addchar_at(t_vector *vector, char c, size_t index);
void			vct_replace_char_at(t_vector *vector, char c, size_t index);
int8_t			vct_pushstr(t_vector *vector, char *str);
int8_t			vct_addstr_at(t_vector *vector, char *str, size_t index);

/*
**********************
**  	REMOVE	    **
**********************
*/
void			vct_pop(t_vector *vector, size_t len);
void			vct_pop_from(t_vector *vector, size_t len, size_t index);

/*
**********************
**  	 JOIN	    **
**********************
*/
t_vector		*vct_dup(t_vector *vector);
int8_t			vct_strjoin(t_vector *vector, char *str);
int8_t			vct_cat(t_vector *dest, t_vector *src);
t_vector		*vct_join(t_vector *dest, t_vector *src);
t_vector		*vct_joinfree(t_vector **dest, t_vector **src,
							int first_or_second_or_both);
/*
**********************
**  	 FILL	    **
**********************
*/
int8_t			vct_fill_after(t_vector *vector, char c, size_t nbr);
int8_t			vct_fill_before(t_vector *vector, char c, size_t nbr);

/*
**********************
**  	SEARCH	    **
**********************
*/
ssize_t			vct_chr(t_vector *vector, char c);
ssize_t			vct_chr_str(t_vector *vector, char *find);
int8_t			vct_replace_char(t_vector *vector, char c, char replace);

/*
**********************
**  	APPLY	    **
**********************
*/
int				vct_apply(t_vector *vector, enum e_apply type);

/*
**********************
**  	CONV	    **
**********************
*/
t_vector		*ft_ftoa(double value, uint64_t precision, uint32_t option);
t_vector		*ft_fldtoa(long double val, uint64_t preci, uint32_t opt);

/*
** vct_print
** vct_ndup
** vct_trim
** vct_split
** vct_splitchr
** vct_read_line
*/

#endif
