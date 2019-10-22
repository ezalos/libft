/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_data_base.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:05:08 by gtaja             #+#    #+#             */
/*   Updated: 2019/10/22 16:05:08 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_DATA_BASE_H
# define AUTO_DATA_BASE_H

size_t		ft_access_htable(size_t key);
int			ft_get_file_in_htable(char *str);
ssize_t		ft_hfunc(void *data, size_t size);
size_t		**ft_htable_mem(void);
ssize_t		ft_store_htable(void *data, size_t size,
		ssize_t (*hf)(void *, size_t));
ssize_t		ft_unstore_htable(void *data, size_t size,
		ssize_t (*hf)(void *, size_t));

#endif
