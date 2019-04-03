#ifndef AUTO_TERMINAL_H
# define AUTO_TERMINAL_H

char		*ft_str_rgbcolor(char background, int red, int green, int blue);
int			ft_place_cursor(size_t line, size_t column);
int			ft_rgb_bcolor(int red, int green, int blue);
int			ft_rgb_color(int red, int green, int blue);
void		ft_press_any_key(void);
void		ft_print_address_color(intmax_t nb);
void		ft_putstr_color(char const *s, int r, int g, int b);
void		ft_wait_pls(uintmax_t wait);

#endif
