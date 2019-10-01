/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:10:11 by gtaja             #+#    #+#             */
/*   Updated: 2019/09/24 21:16:12 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strendswith(char *str, char *ends)
{
	int	i;
	int	j;

	i = ft_strlen(ends) - 1;
	j = ft_strlen(str) - 1;
	if (i > j)
		return (0);
	while (i >= 0)
	{
		if (ends[i] != ends[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}
