/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartwith.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:10:11 by gtaja             #+#    #+#             */
/*   Updated: 2019/09/24 21:14:34 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstartwith(char *str, char *start)
{
	if (ft_strlen(start) > ft_strlen(str))
		return (0);
	while (*start != '\0')
	{
		if (*start != *str)
			return (0);
		start++;
		str++;
	}
	return (1);
}
