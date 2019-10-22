/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_greg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:25:59 by ldevelle          #+#    #+#             */
/*   Updated: 2019/10/22 09:25:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_GREG_H
# define AUTO_GREG_H

int			ft_strappend(char **base, char *more);
int			ft_strendswith(char *str, char *ends);
char		*ft_strndup(char *str, size_t n);
int			ft_strstartwith(char *str, char *start);
char		*ft_strtrim_free(char *str);
int			gnl(int fd, char **line);

#endif
