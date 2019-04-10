/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:36:08 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/10 23:41:36 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_tab(char *name, int *tab, int step, int size)
{
	int		seuil;
	int		len;
	int		i;
	int		x;
	int		quant;

	i = 0;
	len = ft_nb_len(tab[size-1], 0);
	seuil = tab[i];
	x = 0;
	quant = (size / 1000) + 1;
	ft_printf("%~{255;255;0}Printing\t%~{255;0;0}%s\t%~{155;155;255}%s%~{255;255;0}\n", name + ft_strlen("../push_swap/tests/count/"), name);
	ft_printf("Possesses %~{155;155;255}%d%~{255;255;0} values\t", size);
	ft_printf("Ranging from %~{155;155;255}%d%~{255;255;0} to %~{155;155;255}%d%~{255;255;0}\n", tab[0], tab[size - 1]);
	ft_printf("Whith step of %~{155;155;255}%d%~{255;255;0}  \t", step);
	ft_printf("Compression factor: %~{155;155;255}%d%~{255;255;0}\n", quant);
	ft_printf("\n%~{255;150;150}%*d%~{}|%~{150;255;150}", len, seuil);
	while (i < size)
	{
		if (tab[i] < seuil + step)
			x++;
		else
		{
			ft_printf("%0*d", x / quant, 0);
			x = 0;
			seuil += step;
			ft_printf("\n%~{255;150;150}%*d%~{}|%~{150;255;150}", len, seuil);
			i--;
		}
		i++;
	}
	seuil += step;
	ft_printf("%0*d\n", x / quant, 0);
	x = 0;
	// ft_printf("\n%~{255;150;150}%*d%~{}|%~{150;255;150}", len, seuil);
}

int		get_tab_from_file(char *str, int **tab)
{
	size_t	fd;
	// int		*tab;
	int		i;
	char	*line;

	fd = open(str, O_RDONLY);
	*tab = ft_memalloc(sizeof(int) * 5000);
	i = -1;
	while (get_next_line(fd, &line) > 0)
		(*tab)[++i] = ft_atoi(line);
	close(fd);
	return (i + 1);
}

int		get_n_step(int *tab, int size, int n)
{
	int		range;

	range = tab[size - 1] - tab[0];
	range /= n;
	if (!range)
		range++;
	return (range);
}

int		create_new_file(char *str)
{
	int		fd;
	int		i;
	char	*name;
	char	*num;

	fd = -1;
	name = ft_strdup(str);
	num = NULL;
	i = 0;
	while (fd == -1)
	{
		if (-1 != (fd = open(name, O_CREAT|O_EXCL|O_RDWR, S_IRWXU|S_IRWXG|S_IRWXO)))
			break ;
		else
		{
			ft_strdel(&name);
			ft_strdel(&num);
			num = ft_nb_to_a(i, 0);
			name = ft_strjoin_multi(3, str, "_", num);
		}
		i++;
	}
	ft_strdel(&name);
	ft_strdel(&num);
	return (fd);
}

int		main(int ac, char **av)
{
	// char			*line;
	int		*tab;
	int		size;
	// size_t			fd;
	// intmax_t		i;
	// intmax_t		av_one;
	// intmax_t		av_two;

	if (ac != 2)
		return (0);
	size = get_tab_from_file(av[1], &tab);
	ft_squick_sort(&tab, 0, size - 1);
	print_tab(av[1], tab, get_n_step(tab, size, 20), size);
	// ft_create_new_file(av[1]);
	// (void)av;
	// av_one = INTMAX_MIN;
	// av_two = INTMAX_MAX;
	// i = 0;
	// fd = open(av[1], O_RDONLY);
	// while (1){
	// 	ft_printf("%~{!}", ft_random(-10, 10, 0, 0));
	// }
	return (0);
}
