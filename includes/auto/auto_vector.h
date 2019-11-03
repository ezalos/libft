/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_vector.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 07:40:18 by gtaja             #+#    #+#             */
/*   Updated: 2019/11/03 15:32:30 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_VECTOR_H
# define AUTO_VECTOR_H

int8_t		vct_addchar(t_vector *vector, char c);
int8_t		vct_addchar_at(t_vector *vector, char c, size_t index);
int8_t		vct_addstr_at(t_vector *vector, char *str, size_t index);
void		vct_bzero(t_vector *vector);
int8_t		vct_cat(t_vector *dest, t_vector *src);
ssize_t		vct_chr(t_vector *vector, char c);
ssize_t		vct_chr_str(t_vector *vector, char *find);
void		vct_del(t_vector **vector);
t_vector	*vct_dup(t_vector *vector);
int8_t		vct_fill_after(t_vector *vector, char c, size_t size);
int8_t		vct_fill_before(t_vector *vector, char c, size_t size);
char		vct_getchar_at(t_vector *vector, size_t index);
char		*vct_getstr(t_vector *vector);
int8_t		vct_increase_scale(t_vector *vector, size_t scale);
t_vector	*vct_join(t_vector *dest, t_vector *src);
t_vector	*vct_join_free(t_vector **dest, t_vector **src,
		int first_or_second_or_both);
size_t		vct_len(t_vector *vector);
t_vector	*vct_new(size_t size);
t_vector	*vct_newstr(char *str);
void		vct_pop(t_vector *vector, size_t len);
void		vct_pop_from(t_vector *vector, size_t len, size_t index);
int8_t		vct_pushstr(t_vector *vector, char *str);
int8_t		vct_replace_char(t_vector *vector, char c, char replace);
void		vct_replace_char_at(t_vector *vector, char c, size_t index);
int8_t		vct_strjoin(t_vector *vector, char *str);

#endif
