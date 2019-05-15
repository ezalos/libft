#ifndef AUTO_INOUT_H
# define AUTO_INOUT_H

int			ft_nb_char_to_int(char c);
int			ft_intlen(int n);
size_t		ft_u_nb_len(uintmax_t nb, size_t base);
int			ft_is_str_bigger_than_int(char *str);
int			ft_patoi(const char *str);
int			ft_atoi(const char *src);
char		*ft_itoa(int n);
char		*ft_nb_to_a(intmax_t n, size_t base);
size_t		ft_nb_len(intmax_t n, size_t base);
char		*ft_u_nb_to_a(uintmax_t n, size_t base);
int			get_next_line(const int fd, char **line);
int			ft_putstr_r0_fd(char const *s, int fd);
void		*ft_putstr_rnull(char const *s);
int			ft_putstr_r0(char const *s);
void		ft_putnbr(int n);
void		ft_putbnbr_str(int i, uintmax_t n, char *nb, size_t base);
size_t		ft_puttab(const char *s, size_t separation);
size_t		ft_puttab_len(size_t length, size_t separation, size_t n);
void		ft_putendl(char const *s);
void		ft_putstr(char const *s);
void		ft_putnstr(char const *s, size_t n);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);

#endif
