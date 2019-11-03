/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_maths.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 07:40:18 by gtaja             #+#    #+#             */
/*   Updated: 2019/11/03 07:40:18 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_MATHS_H
# define AUTO_MATHS_H

int			ft_abs(int x);
int			ft_factorial(int nb);
float		ft_fsqrt(int nb, int limite);
intmax_t	ft_nb_in_range(intmax_t min, intmax_t max, intmax_t nb);
intmax_t	ft_power(int nb, int power);
intmax_t	ft_sum_to_nb(intmax_t nb);
intmax_t	ft_rand(intmax_t max, intmax_t seed);
intmax_t	ft_random(intmax_t min, intmax_t max, intmax_t ran, size_t len);
intmax_t	ft_simple_random(intmax_t mn, intmax_t mx, intmax_t r, size_t l);
intmax_t	ft_seed_adress(intmax_t min, intmax_t max);
intmax_t	ft_seed_gnl(intmax_t min, intmax_t max);
intmax_t	ft_seed_string(const char *str);
intmax_t	ft_seed_time(intmax_t min, intmax_t max);
float		ft_fpart(float x);
int			ft_ipart(float x);
float		ft_rfpart(float x);
int			ft_round(float i);
int			ft_round_upper(float i);
void		ft_quick_sort(int **array, int low, int high, int *count);
void		ft_squick_sort(int **array, int low, int high);
int			ft_fibonacci(int index);
int			*ft_nprime(int limite);

#endif
