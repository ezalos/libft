/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_libft.a_.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:25:15 by ezalos            #+#    #+#             */
/*   Updated: 2020/10/02 17:00:36 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_LIBFT_A__H
# define AUTO_LIBFT_A__H

int			add_htag(t_printf *print, char **str);
int			add_minimum_width(t_printf *print, char **str);
void		add_minimum_width_0(t_printf *print);
int			add_precison(t_printf *print, char **str);
int			add_sign(char **str);
int			add_space(t_printf *print, char **str);
void		add_type(const char **f, t_printf *print);
int			ajust_flags(t_printf *print, char **str);
int			bonus_gestion(t_printf *print, const char **f);
void		check_arg(t_printf *print, const char **f);
void		check_flags(const char c, t_arg *arg);
void		check_min_or_pre2(t_printf *print,
			const char **f,
			int *tmp,
			int pres);
void		check_minimum_width_or_precision(t_printf *print, const char **f);
void		check_modifier(const char **f, t_arg *arg);
double		cl(clock_t t);
void		*cnalloc(const void *content, size_t size_content);
int			color_gestion(t_printf *print, const char **f);
int			color_get_rgb(t_printf *print, const char **f, char *str);
int			color_nb_with_prand_color(t_printf *print,
			const char **f,
			char *str);
int			color_rand_color_based_int_str(t_printf *print, const char **f,
			char *str);
int			color_reset(t_printf *print, const char **f, char *str);
int			create_struct_for_fd(int fd, char **line, t_list *tmp);
int			float_exception(t_printf *print, double ldb);
void		float_no_htag(t_printf *print, char *int_part, char *decimal_part);
int			ft_abs(int x);
size_t		ft_access_htable(size_t key);
void		ft_add_to_file(char *name, char *data);
int			ft_atoi(const char *src);
void		ft_burn_garbage(char *str);
void		ft_bzero(void *s, size_t n);
int			ft_char_srch(const char src, const char *dlt);
void		ft_clean_garbage(void);
int			ft_create_new_file(char *str);
void		ft_del(void *content, size_t size);
float		ft_fabs(float x);
int			ft_factorial(int nb);
int			ft_fibonacci(int index);
float		ft_fpart(float x);
void		ft_free_with_nalloc(void *elem);
float		ft_fsqrt(int nb, int limite);
void		**ft_garbage_collector(void);
size_t		ft_get_file(char *path, char **file);
int			ft_get_file_in_htable(char *str);
ssize_t		ft_get_size_file(char *str);
int			ft_get_tab_from_file(char *str, int **tab, int lines);
int			ft_gnl(const int fd, char **line);
ssize_t		ft_hfunc(void *data, size_t size);
size_t		**ft_htable_mem(void);
int			ft_intlen(int n);
int			ft_ipart(float x);
int			ft_is_str_bigger_than_int(char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isupper(int c);
char		*ft_itoa(int n);
size_t		ft_lst_count(t_list *lst, size_t i);
size_t		ft_lst_free(t_list **delete_me);
t_list		*ft_lst_reach_end(t_list *alst);
void		ft_lstadd(t_list **alst, t_list *new, int position);
void		ft_lstadd_end(t_list *alst, t_list *new);
void		ft_lstadd_here(t_list *alst, t_list *new);
void		ft_lstadd_start(t_list **alst, t_list *new);
t_list		*ft_lstcut(t_list **alst, int indx);
void		ft_lstcutone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list		*ft_lstfind_th(t_list *lst, size_t umpteenth);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list		*ft_lstnew(void const *content, size_t content_size);
t_list		*ft_lstnew_ptr(void const *content, size_t content_size);
int			ft_match(char *s1, char *s2);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_memdel(void **ap);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);
int			ft_nb_char_to_int(char c);
intmax_t	ft_nb_in_range(intmax_t min, intmax_t max, intmax_t nb);
size_t		ft_nb_len(intmax_t n, size_t base);
char		*ft_nb_to_a(intmax_t n, size_t base);
int			ft_nmatch(char *s1, char *s2);
int			*ft_nprime(int limite);
int			ft_patoi(const char *str);
int			ft_place_cursor(size_t line, size_t column);
intmax_t	ft_power(int nb, int power);
void		ft_press_any_key(void);
void		ft_print_address_color(intmax_t nb);
int			ft_printf(const char *format, ...);
void		ft_progress(const char *name, intmax_t now, intmax_t max);
char		*ft_pstrnstr(const char *m, const char *a, size_t len);
void		ft_putbnbr_str(int i, uintmax_t n, char *nb, size_t base);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr(int n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnstr(char const *s, size_t n);
void		ft_putstr(char const *s);
void		ft_putstr_color(char const *s, int r, int g, int b);
void		ft_putstr_fd(char const *s, int fd);
int			ft_putstr_r0(char const *s);
int			ft_putstr_r0_fd(char const *s, int fd);
void		*ft_putstr_rnull(char const *s);
size_t		ft_puttab(const char *s, size_t separation);
size_t		ft_puttab_len(size_t length, size_t separation, size_t n);
void		ft_quick_sort(int **array, int low, int high, int *count);
intmax_t	ft_rand(intmax_t max, intmax_t seed);
intmax_t	ft_random(intmax_t min, intmax_t max, intmax_t ran, size_t len);
char		*ft_read_file(int fd, int *size);
float		ft_rfpart(float x);
int			ft_rgb_bcolor(int red, int green, int blue);
int			ft_rgb_color(int red, int green, int blue);
int			ft_round(float i);
int			ft_round_upper(float i);
intmax_t	ft_seed_adress(intmax_t min, intmax_t max);
intmax_t	ft_seed_gnl(intmax_t min, intmax_t max);
intmax_t	ft_seed_string(const char *str);
intmax_t	ft_seed_time(intmax_t min, intmax_t max);
intmax_t	ft_simple_random(intmax_t mn, intmax_t mx, intmax_t r, size_t l);
void		ft_squick_sort(int **array, int low, int high);
ssize_t		ft_store_htable(void *data, size_t size,
			ssize_t (*hf)(void *, size_t));
char		*ft_str_rgbcolor(char background, int red, int green, int blue);
int			ft_strappend(char **base, char *more);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strchr(const char *s, int c);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dest, const char *src);
void		ft_strdel(char **as);
void		ft_strdel_multi(size_t nb, ...);
char		*ft_strdup(const char *src);
int			ft_strendswith(char *str, char *ends);
int			ft_strequ(char const *s1, char const *s2);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_multi(size_t nb, ...);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *dest, const char *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strndup(char *str, size_t n);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strnew(size_t size);
size_t		ft_strnlen(const char *s, size_t size);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strrealloc(const char *src, size_t size);
char		*ft_strrev(char *str, size_t size);
char		**ft_strsplit(char const *s, char c);
int			ft_strstartwith(char *str, char *start);
char		*ft_strstr(const char *meule_de_foin, const char *aiguille);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
char		*ft_strtrim_free(char *str);
intmax_t	ft_sum_to_nb(intmax_t nb);
void		ft_swap(void *one, void *two, size_t size);
t_tab		*ft_tab_access(t_tab *tab, int dir_y, int dir_x, int rot);
int			ft_tab_connect_dir(size_t d_a, t_tab *l_a, t_tab *l_b, size_t d_b);
void		ft_tab_connect_structs(t_tab *t_one, t_tab *t_two, size_t dir_one);
int			ft_tab_cut_loop(t_tab *tab, size_t dir);
t_tab		*ft_tab_cutone(t_tab *to_cut);
size_t		ft_tab_delete_row(t_tab *tab, size_t dir);
size_t		ft_tab_delete_row_len(t_tab *tab, size_t dir, size_t len);
size_t		ft_tab_dir_clock(size_t dir);
size_t		ft_tab_dir_nclock(size_t dir, size_t move);
size_t		ft_tab_dir_rclock(size_t dir);
size_t		ft_tab_dir_reverse(size_t dir);
t_tab		*ft_tab_dirth(t_tab *tab, size_t dir, size_t umpteenth);
size_t		ft_tab_lendir(t_tab *tab, size_t dir);
int			ft_tab_print_dir(t_tab *tab, size_t dir, int lin);
int			ft_tab_print_one_elmnt(t_tab *tmp, size_t lin,
			size_t col, int structh);
t_tab		*ft_tab_reach_end(t_tab *tab, size_t dir);
t_tab		*ft_tab_square_it(t_tab *tab, size_t dir);
void		ft_tabadd(t_tab **tab, t_tab *new, size_t dir, int umpteenth);
void		ft_tabadd_end(t_tab *alst, t_tab *new, size_t dir);
void		ft_tabadd_here(t_tab *alst, t_tab *new, size_t dir);
void		ft_tabadd_start(t_tab **alst, t_tab *new, size_t dir);
void		ft_tabiter(t_tab *t, size_t d,
			int (*f)(t_tab *, size_t, int), size_t s);
size_t		ft_tabloop_it(t_tab *tab, size_t dir);
size_t		ft_tabloop_itis(t_tab *tab, size_t dir);
size_t		ft_tabloop_lendir(t_tab *tab, size_t dir);
t_tab		*ft_tabnew_dir(size_t len, size_t dir);
t_tab		*ft_tabnew_ptr(void const *content, size_t content_size);
t_tab		*ft_tabnew_rectangle(size_t x_axis, size_t y_axis, size_t x_dir);
int			ft_tolower(int c);
int			ft_toupper(int c);
size_t		ft_u_nb_len(uintmax_t nb, size_t base);
char		*ft_u_nb_to_a(uintmax_t n, size_t base);
ssize_t		ft_unstore_htable(void *data, size_t size,
			ssize_t (*hf)(void *, size_t));
void		ft_wait_pls(uintmax_t wait);
char		*get_decimal_from_float(t_arg *arg, long double ldb);
char		*get_int_from_float(intmax_t ldb, char neg);
int			get_line(t_list *gnl, char **line);
int			get_line_2(t_gnl *gnl, char **line);
int			get_next_line(const int fd, char **line);
int			get_printf(t_printf *print, char **str, size_t content_size);
int			get_value_of_star_or_nb(t_printf *print, const char **f, int *tmp);
char		*get_value_of_star_or_str(t_printf *print,
			const char **f,
			char **tmp);
int			gnl(int fd, char **line);
int			init_struct(t_printf *print, const char *format);
void		init_struct_arg(t_printf *print);
t_time		*list_exchange(t_time **timee);
void		*malloco(size_t size_content);
void		*nalloc(size_t size_content);
void		neg_gestion(char *neg, long double *ldb);
int			output_invisible_char(size_t fd, char *str, size_t size, int color);
int			output_string(t_printf *print);
void		padding_after(t_rbt *node);
void		padding_before(t_rbt *node, size_t space);
int			parse_add_arg(char *name, char *help);
int			parse_add_option(char opt, char *name, char *help);
int			parse_args(int ac, char **av);
void		parse_args_init(int ac, char **av);
int			parse_args_save(int arg_place, t_argument *argument, int arg_type);
int			parse_args_unit(int index, char *av_arg);
void		parse_free(void);
t_argument	*parse_get(char *name);
t_argument	*parse_get_arg(char *name, int empty);
t_argument	*parse_get_opt(char opt, int empty);
t_parse		*parse_mem(void);
t_parse		*parse_new(char *name, char *help);
int			parse_opts_double_dash(int index, char *av_arg);
int			parse_opts_simple_dash(int index, char *av_arg);
void		parse_print(void);
void		parse_print_arg(t_argument *arg);
int			parse_usage(void);
void		parse_usage_command(t_parse *arg);
void		parse_usage_options(t_parse *arg);
int			parsing(t_printf *print);
int			parsing_float(t_printf *print);
int			parsing_integer(t_printf *print);
int			parsing_unsigned_integer(t_printf *print);
int			paste_char_in_printf(t_printf *print, char str);
int			paste_float_in_printf(t_printf *print, char *str);
int			paste_format_in_printf(t_printf *print);
int			paste_int_in_printf(t_printf *print, char *str);
int			paste_str_in_printf(t_printf *print, char *str);
int			print_binary(t_printf *print, void *bin);
int			print_character(t_printf *print, char str);
void		print_elements(t_time *tmp, double total, int tab);
int			print_float(t_printf *print, long double ldb);
int			print_integer(t_printf *print, intmax_t nb);
int			print_node_info(t_rbt *root);
int			print_pointer(t_printf *print, void *ptr);
int			print_string(t_printf *print, char *str);
char		*print_string_to_binary(unsigned char *converter,
			size_t size_thing);
void		print_time(void);
void		print_total(double total);
int			print_unsigned_integer(t_printf *print, uintmax_t nb);
void		reajust_hatg(t_printf *print, char *str);
void		reajust_p(char *str);
void		reajust_sign(char *str);
char		*round_float_str(char *str);
char		*round_move_nb(char *str, size_t len);
char		*s_to_bin(unsigned char *str, int length);
int			save_file(t_list *gnl, char *buf, int read);
int			send_exceptions(char **line, t_list *gnl);
int			send_line(char **line, t_list *gnl);
void		sort_list(t_time **timee);
int			*switch_garbage(void);
t_time		*time_exe(const char *s);
void		tree_delete_case_1(t_rbt *node);
void		tree_delete_case_2(t_rbt *node);
void		tree_delete_case_3(t_rbt *node);
void		tree_delete_case_4(t_rbt *node);
void		tree_delete_case_5(t_rbt *node);
void		tree_delete_case_6(t_rbt *node);
void		tree_delete_one_child(t_rbt *node, t_rbt_free_content *func);
void		tree_free(t_rbt *root, t_rbt_free_content *func);
t_rbt		*tree_grand_parent(t_rbt *node);
int			tree_inorder(t_rbt *root, t_rbt_inorder *func);
long long	tree_inorder_long_long(t_rbt *root,
			t_rbt_inorder_long_long *func);
void		*tree_inorder_ptr(t_rbt *root, t_rbt_inorder_ptr *func);
int			tree_inrorder(t_rbt *root, t_rbt_inorder *func);
void		*tree_inrorder_ptr(t_rbt *root, t_rbt_inorder_ptr *func);
t_rbt		*tree_insert(t_rbt *root, void *content, int key);
void		tree_insert_case_1(t_rbt *n);
void		tree_insert_case_2(t_rbt *n);
void		tree_insert_case_3(t_rbt *n);
void		tree_insert_case_4(t_rbt *n);
t_rbt		*tree_insert_func(t_rbt *root, void *content, t_rbt_compare *func);
void		tree_insert_recurse(t_rbt *root, t_rbt *n);
void		tree_insert_recurse_func(t_rbt *root,
			t_rbt *n,
			t_rbt_compare *func);
void		tree_insert_repair(t_rbt *n);
t_rbt		*tree_new_node(void *content);
t_rbt		*tree_parent(t_rbt *node);
void		tree_print(t_rbt *node, size_t deep);
void		tree_print_elem(t_rbt *node);
void		tree_recoloring(t_rbt *node);
void		tree_replace_node(t_rbt *node, t_rbt *child);
t_rbt		*tree_root(t_rbt *node);
void		tree_rot_left(t_rbt *node);
void		tree_rot_right(t_rbt *node);
t_rbt		*tree_sibling(t_rbt *node);
void		tree_simple_print(t_rbt *root);
void		tree_str(t_rbt *root);
t_rbt		*tree_uncle(t_rbt *node);
int			type_dic(t_printf *print, char **str);
int			type_empty(t_printf *print, char **str);
int			type_oux(t_printf *print, char **str);
int			type_p(char **str, t_printf *print);
int			type_s(t_printf *print, char **str);
int			update_gnl_struct(t_gnl *gnl, char **line);
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
int			we_just_found_a_percent(t_printf *print);
void		write_0(t_printf *print, char **str);

#endif
