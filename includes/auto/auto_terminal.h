/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_terminal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:14:56 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/15 13:14:56 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_TERMINAL_H
# define AUTO_TERMINAL_H

void		ft_print_address_color(intmax_t nb);
void		ft_putstr_color(char const *s, int r, int g, int b);
int			ft_rgb_bcolor(int red, int green, int blue);
int			ft_rgb_color(int red, int green, int blue);
char		*ft_str_rgbcolor(char background, int red, int green, int blue);
int			ft_place_cursor(size_t line, size_t column);
void		ft_press_any_key(void);
void		ft_progress(const char *name, intmax_t now, intmax_t max);
void		ft_wait_pls(uintmax_t wait);

#endif
