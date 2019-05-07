/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:30 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 19:33:38 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct			s_printfesse
{
	char				exist;
	char				background;
	int					red;
	int					green;
	int					blue;
	int					line;
	int					column;
	char				*base_in;
	char				*base_out;
	char				*rand_str;
	int					rand_nb;

}						t_printfesse;

typedef struct			s_arg
{
	int					zero_exist;
	char				type;
	int					minimum_width;
	int					ajust_left;
	char				space_filled;
	int					sign;
	int					htag;
	int					space;
	int					precision;
	int					precision_exist;
	int					modifier_h;
	int					modifier_l;
	int					modifier_ll;
}						t_arg;

typedef struct			s_printf
{
	t_list				*lst_to_print;
	const char			*format;
	char				*start_format;
	va_list				ap;
	char				*printf;
	char				*last_type;
	char				lets_print;
	int					i;
	size_t				size_all;
	size_t				fd;
	char				invisible;
	t_arg				arg[1];
	t_printfesse		bonus[1];
}						t_printf;

/*
** typedef struct			s_float
** {
** 	unsigned char		sign[1 + 1];
** 	unsigned char		exposant[8 * 3 + 1];
** 	unsigned char		mantisse[5 * 8];
** }						t_float;
**
** typedef struct			s_pre_min
** {
** 	size_t				len_str;
** 	size_t				size_m;
** 	size_t				size_p;
** 	int					neg;
** }						t_pre_min;
*/

/*
** PRINTF
*/
int						ft_printf(const char *format, ...);

/*
** INIT
*/
void					init_struct_arg(t_printf *print);
int						init_struct(t_printf *print, const char *format);

/*
** PARSING
*/
int						parsing(t_printf *print);

/*
** PRECISION WIDTH
*/
int						ajust_flags(t_printf *print, char **str);

/*
** TYPES
*/
int						print_unsigned_integer(t_printf *print, uintmax_t nb);
int						print_pointer(t_printf *print, void *ptr);
int						print_float(t_printf *print, long double ldb);
int						print_string(t_printf *print, char *str);
char					*ft_nb_to_a(intmax_t n, size_t base);
int						print_integer(t_printf *print, intmax_t nb);
int						print_character(t_printf *print, char str);
int						print_others(t_printf *print, void *str);
int						print_binary(t_printf *print, void *bin);
char					*get_int_from_float(intmax_t ldb, char neg);
char					*get_decimal_from_float(t_arg *arg, long double ldb);
char					*round_move_nb(char *str, size_t len);

/*
** MALLOC AND MOVE
*/
int						get_printf(t_printf *print, char **str,
	size_t content_size);
int						paste_format_in_printf(t_printf *print);
int						paste_int_in_printf(t_printf *print, char *str);
int						paste_str_in_printf(t_printf *print, char *str);
int						paste_float_in_printf(t_printf *print, char *str);
int						paste_char_in_printf(t_printf *print, char str);

/*
** CHEACK_ARGS
*/
void					check_flags(const char c, t_arg *arg);
void					check_minimum_width_or_precision(t_printf *print,
	const char **f);
void					check_modifier(const char **f, t_arg *arg);
void					check_arg(t_printf *print, const char **f);
char					*get_value_of_star_or_str(t_printf *print,
	const char **f, char **tmp);
int						get_value_of_star_or_nb(t_printf *print,
	const char **f, int *tmp);
int						add_htag(t_printf *print, char **str);
int						add_sign(char **str);
int						add_space(t_printf *print, char **str);
void					reajust_sign(char *str);
void					reajust_hatg(t_printf *print, char *str);
int						add_minimum_width(t_printf *print, char **str);
int						add_precison(t_printf *print, char **str);
int						type_p(char **str, t_printf *print);

/*
** OUTPUT
*/
int						output_string(t_printf *print);

/*
** BONUS GESTION
*/
int						bonus_gestion(t_printf *print, const char **f);
int						color_gestion(t_printf *print, const char **f);
int						tab_gestion(t_printf *print, const char **f);
int						cursor_gestion(t_printf *print, const char **f);

#endif
