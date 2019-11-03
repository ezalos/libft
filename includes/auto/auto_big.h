/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_big.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 07:40:17 by gtaja             #+#    #+#             */
/*   Updated: 2019/11/03 15:32:54 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_BIG_H
# define AUTO_BIG_H

int			type_oux(t_printf *print, char **str);
int			type_dic(t_printf *print, char **str);
int			type_empty(t_printf *print, char **str);
int			type_s(t_printf *print, char **str);
int			ajust_flags(t_printf *print, char **str);
int			color_reset(t_printf *print, const char **f, char *str);
int			color_get_rgb(t_printf *print, const char **f, char *str);
int			color_nb_with_prand_color(t_printf *print, const char **f,
		char *str);
int			color_rand_color_based_int_str(t_printf *print, const char **f,
		char *str);
int			color_gestion(t_printf *print, const char **f);
int			bonus_gestion(t_printf *print, const char **f);
void		add_type(const char **f, t_printf *print);
void		check_arg(t_printf *print, const char **f);
void		check_flags(const char c, t_arg *arg);
int			get_value_of_star_or_nb(t_printf *print, const char **f, int *tmp);
char		*get_value_of_star_or_str(t_printf *print, const char **f,
	char **tmp);
void		check_min_or_pre2(t_printf *print, const char **f, int *tmp,
	int pres);
void		check_minimum_width_or_precision(t_printf *print, const char **f);
int			paste_format_in_printf(t_printf *print);
int			we_just_found_a_percent(t_printf *print);
int			ft_printf(const char *format, ...);
void		add_minimum_width_0(t_printf *print);
void		write_0(t_printf *print, char **str);
int			get_printf(t_printf *print, char **str, size_t content_size);
int			paste_char_in_printf(t_printf *print, char str);
int			paste_float_in_printf(t_printf *print, char *str);
int			paste_int_in_printf(t_printf *print, char *str);
int			paste_str_in_printf(t_printf *print, char *str);
void		init_struct_arg(t_printf *print);
int			init_struct(t_printf *print, const char *format);
int			output_invisible_char(size_t fd, char *str, size_t size, int color);
int			output_string(t_printf *print);
int			parsing_integer(t_printf *print);
int			parsing_unsigned_integer(t_printf *print);
int			parsing_float(t_printf *print);
int			parsing(t_printf *print);
void		reajust_sign(char *str);
void		reajust_hatg(t_printf *print, char *str);
int			add_minimum_width(t_printf *print, char **str);
int			add_precison(t_printf *print, char **str);
int			add_htag(t_printf *print, char **str);
int			add_sign(char **str);
int			add_space(t_printf *print, char **str);
void		reajust_p(char *str);
int			type_p(char **str, t_printf *print);
char		*s_to_bin(unsigned char *str, int length);
char		*ft_strrev(char *str, size_t size);
char		*print_string_to_binary(unsigned char *converter,
	size_t size_thing);
int			print_binary(t_printf *print, void *bin);
int			print_character(t_printf *print, char str);
int			float_exception(t_printf *print, double ldb);
char		*round_float_str(char *str);
void		float_no_htag(t_printf *print, char *int_part, char *decimal_part);
void		neg_gestion(char *neg, long double *ldb);
int			print_float(t_printf *print, long double ldb);
char		*get_int_from_float(intmax_t ldb, char neg);
char		*get_decimal_from_float(t_arg *arg, long double ldb);
char		*round_move_nb(char *str, size_t len);
int			print_integer(t_printf *print, intmax_t nb);
int			print_pointer(t_printf *print, void *ptr);
int			print_string(t_printf *print, char *str);
int			print_unsigned_integer(t_printf *print, uintmax_t nb);
double		cl(clock_t t);
t_time		*list_exchange(t_time **timee);
void		sort_list(t_time **timee);
void		print_elements(t_time *tmp, double total, int tab);
void		print_total(double total);
void		print_time(void);
t_time		*time_exe(const char *s);

#endif
