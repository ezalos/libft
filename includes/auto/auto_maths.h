#ifndef AUTO_MATHS_H
# define AUTO_MATHS_H

float		ft_fsqrt(int nb, int limite);
int			*ft_nprime(int limite);
int			ft_factorial(int nb);
int			ft_fibonacci(int index);
int			ft_round(float i);
int			ft_round_upper(float i);
intmax_t	ft_nb_in_range(intmax_t min, intmax_t max, intmax_t nb);
intmax_t	ft_power(int nb, int power);
intmax_t	ft_random(intmax_t min, intmax_t max, intmax_t rando, size_t len);
intmax_t	ft_seed_adress(intmax_t min, intmax_t max);
intmax_t	ft_seed_gnl(intmax_t min, intmax_t max);
intmax_t	ft_seed_time(intmax_t min, intmax_t max);
intmax_t	ft_simple_random(intmax_t min, intmax_t max, intmax_t rando, size_t len);
intmax_t	ft_sum_to_nb(intmax_t nb);
void		ft_quick_sort(int **array, int low, int high, int *count);
void		ft_squick_sort(int **array, int low, int high);

#endif