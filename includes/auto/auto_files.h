/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_files.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:42:56 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/22 17:42:56 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_FILES_H
# define AUTO_FILES_H

void		ft_add_to_file(char *name, char *data);
int			ft_create_new_file(char *str);
ssize_t		ft_get_size_file(char *str);
int			ft_get_tab_from_file(char *str, int **tab, int lines);
char		*ft_read_file(int fd);

#endif
