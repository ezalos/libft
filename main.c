/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:36:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 19:11:54 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

int		main(void)
{
	int		v;
	int		i;

	v = 1000;
	printf("yo\n");
	int *a = nalloc(1);
	printf("A\n");
	ft_memdel(&a);
	i = v;
	// while (--i)
	// 	nalloc(1);
	printf("yo\n");
	int *b = nalloc(1);
	printf("B\n");
	ft_memdel(&b);
	nalloc(1);
	nalloc(1);
	nalloc(1);
	nalloc(1);
	i = v;
	// while (--i)
	// 	nalloc(1);
	printf("yo\n");
	int *c = nalloc(1);

	printf("C\n");
	ft_memdel(&c);


	ft_clean_garbage();
	return (0);
}
