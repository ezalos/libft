/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:57:25 by gtaja             #+#    #+#             */
/*   Updated: 2019/10/30 16:20:08 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen_trimed(char const *s)
{
	int	i;

	i = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (s[i])
		i++;
	return (i);
}

static char		*ft_strtrim_greg(char const *s)
{
	int		i;
	int		len;
	char	*result;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen_trimed(s);
	if (!(result = (char*)ft_memalloc((len + 1) * sizeof(char))))
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char			*ft_strtrim_free(char *str)
{
	char	*result;

	result = ft_strtrim_greg(str);
	ft_memdel((void**)&str);
	return (result);
}
