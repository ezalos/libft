/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:14:56 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/15 13:14:56 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_STRUCTURES_H
# define AUTO_STRUCTURES_H

void		ft_lstadd(t_list **alst, t_list *new, int position);
void		ft_lstadd_end(t_list *alst, t_list *new);
void		ft_lstadd_here(t_list *alst, t_list *new);
void		ft_lstadd_start(t_list **alst, t_list *new);
void		ft_lstcutone(t_list **alst, void (*del)(void *, size_t));
t_list		*ft_lstnew(void const *content, size_t content_size);
t_list		*ft_lstnew_ptr(void const *content, size_t content_size);
size_t		ft_lst_free(t_list **delete_me);
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
size_t		ft_lst_count(t_list *lst, size_t i);
t_list		*ft_lst_reach_end(t_list *alst);
t_list		*ft_lstfind_th(t_list *lst, size_t umpteenth);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int			ft_tab_connect_dir(size_t d_a, t_tab *l_a, t_tab *l_b, size_t d_b);
void		ft_tab_connect_structs(t_tab *t_one, t_tab *t_two, size_t dir_one);
int			ft_tab_cut_loop(t_tab *tab, size_t dir);
t_tab		*ft_tab_cutone(t_tab *to_cut);
void		ft_tabadd(t_tab **tab, t_tab *new, size_t dir, int umpteenth);
void		ft_tabadd_end(t_tab *alst, t_tab *new, size_t dir);
void		ft_tabadd_here(t_tab *alst, t_tab *new, size_t dir);
void		ft_tabadd_start(t_tab **alst, t_tab *new, size_t dir);
size_t		ft_tabloop_it(t_tab *tab, size_t dir);
t_tab		*ft_tab_square_it(t_tab *tab, size_t dir);
t_tab		*ft_tabnew_dir(size_t len, size_t dir);
t_tab		*ft_tabnew_ptr(void const *content, size_t content_size);
t_tab		*ft_tabnew_rectangle(size_t x_axis, size_t y_axis, size_t x_dir);
size_t		ft_tab_delete_row(t_tab *tab, size_t dir);
size_t		ft_tab_delete_row_len(t_tab *tab, size_t dir, size_t len);
size_t		ft_tab_dir_clock(size_t dir);
size_t		ft_tab_dir_nclock(size_t dir, size_t move);
size_t		ft_tab_dir_rclock(size_t dir);
size_t		ft_tab_dir_reverse(size_t dir);
size_t		ft_tabloop_itis(t_tab *tab, size_t dir);
size_t		ft_tab_lendir(t_tab *tab, size_t dir);
size_t		ft_tabloop_lendir(t_tab *tab, size_t dir);
t_tab		*ft_tab_access(t_tab *tab, int dir_y, int dir_x, int rot);
t_tab		*ft_tab_dirth(t_tab *tab, size_t dir, size_t umpteenth);
t_tab		*ft_tab_reach_end(t_tab *tab, size_t dir);
int			ft_tab_print_dir(t_tab *tab, size_t dir, int lin);
int			ft_tab_print_one_elmnt(t_tab *tmp, size_t lin,
		size_t col, int structh);
void		ft_tabiter(t_tab *t, size_t d,
		int (*f)(t_tab *, size_t, int), size_t s);

#endif
