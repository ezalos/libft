/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_inout.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 07:40:18 by gtaja             #+#    #+#             */
/*   Updated: 2019/11/03 07:40:18 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_INOUT_H
# define AUTO_INOUT_H

int			ft_atoi(const char *src);
int			ft_intlen(int n);
int			ft_is_str_bigger_than_int(char *str);
char		*ft_itoa(int n);
int			ft_nb_char_to_int(char c);
size_t		ft_nb_len(intmax_t n, size_t base);
char		*ft_nb_to_a(intmax_t n, size_t base);
int			ft_patoi(const char *str);
size_t		ft_u_nb_len(uintmax_t nb, size_t base);
char		*ft_u_nb_to_a(uintmax_t n, size_t base);
int			send_exceptions(char **line, t_list *gnl);
int			send_line(char **line, t_list *gnl);
int			save_file(t_list *gnl, char *buf, int read);
int			get_line(t_list *gnl, char **line);
int			get_next_line(const int fd, char **line);
int			update_gnl_struct(t_gnl *gnl, char **line);
int			get_line_2(t_gnl *gnl, char **line);
int			create_struct_for_fd(int fd, char **line, t_list *tmp);
int			ft_gnl(const int fd, char **line);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putbnbr_str(int i, uintmax_t n, char *nb, size_t base);
void		ft_putnbr(int n);
int			ft_putstr_r0(char const *s);
int			ft_putstr_r0_fd(char const *s, int fd);
void		*ft_putstr_rnull(char const *s);
size_t		ft_puttab(const char *s, size_t separation);
size_t		ft_puttab_len(size_t length, size_t separation, size_t n);
void		ft_putendl(char const *s);
void		ft_putnstr(char const *s, size_t n);
void		ft_putstr(char const *s);

#endif
