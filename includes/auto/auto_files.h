/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_files.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 07:40:18 by gtaja             #+#    #+#             */
/*   Updated: 2019/11/03 07:40:18 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_FILES_H
# define AUTO_FILES_H

void		ft_add_to_file(char *name, char *data);
int			ft_create_new_file(char *str);
size_t		ft_get_file(char *path, char **file);
ssize_t		ft_get_size_file(char *str);
int			ft_get_tab_from_file(char *str, int **tab, int lines);
char		*ft_read_file(int fd, int *size);

#endif
