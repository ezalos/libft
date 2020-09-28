/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:51:38 by ezalos            #+#    #+#             */
/*   Updated: 2020/09/28 12:03:10 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

enum	e_color { BLACK, RED  };

typedef struct		s_rbt
{
	struct s_rbt	*parent;
	struct s_rbt	*left;
	struct s_rbt	*right;

	void			*content;
	int				key;
	enum e_color	color;
}					t_rbt;

typedef	int			(t_rbt_compare)(void *, void *);
typedef	int			(t_rbt_inorder)(t_rbt *);
typedef	void		*(t_rbt_inorder_ptr)(t_rbt *);
typedef	long long	(t_rbt_inorder_long_long)(t_rbt *);

#endif
