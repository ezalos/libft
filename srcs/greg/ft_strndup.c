/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:58:57 by gtaja             #+#    #+#             */
/*   Updated: 2019/10/22 15:37:49 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t n)
{
	size_t	i;
	char	*result;

	i = 0;
	result = malloc((n + 1) * sizeof(char));
	while (str[i] != '\0' && i < n)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
