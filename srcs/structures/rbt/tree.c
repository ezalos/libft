/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:29:49 by ezalos            #+#    #+#             */
/*   Updated: 2020/06/28 14:09:45 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"


/*
 *	Memory management
 */

t_rbt		*tree_new_node(void *content)
{
	t_rbt		*node;

	node = ft_memalloc(sizeof(t_rbt));
	node->content = content;
	node->color = RED;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}



/*
 *	Genealogy
 */


t_rbt		*tree_parent(t_rbt *node)
{
	if (node)
		return (node->parent);
	//DEBUG_ERROR_PRINT("Node sent is NULL, or doesnt have dad");
	return (NULL);
}

t_rbt		*tree_grand_parent(t_rbt *node)
{
	return (tree_parent(tree_parent(node)));
}

t_rbt		*tree_root(t_rbt *node)
{
	t_rbt	*up;

	up = tree_parent(node);
	while (up != NULL)
	{
		//		ft_printf("n: %p\n", node);
		node = up;
		up = tree_parent(node);
	}
	return (node);
}


t_rbt		*tree_sibling(t_rbt *node)
{
	if (node && node->parent)
	{
		if (node == node->parent->left)
		{
			return (node->parent->right);
		}
		else if (node == node->parent->right)
		{
			return (node->parent->left);
		}
	}
	//DEBUG_ERROR_PRINT("");
	return (NULL);
}

t_rbt		*tree_uncle(t_rbt *node)
{
	return ((tree_sibling(tree_parent(node))));
}


/*
 *	Rotations
 */

void	tree_rot_left(t_rbt *node)
{
	t_rbt	*old_root = node;
	t_rbt	*parent;
	t_rbt	*new_root;

	parent = tree_parent(old_root);
	new_root = old_root->right;
	old_root->right = new_root->left;
	new_root->left = old_root;
	old_root->parent = new_root;

	if (old_root->right != NULL)
		old_root->right->parent = old_root;

	if (parent != NULL)
	{
		if (parent->right == old_root)
			parent->right = new_root;
		else
			parent->left = new_root;
		new_root->parent = parent;

	}
	else
		new_root->parent = NULL;


	/*	t_rbt* son_right = node->right;
		t_rbt* parent = tree_parent(node);

	// Since the leaves of a red-black tree are empty,
	// they cannot become internal nodes.
	if(son_right == NULL)
	{
	DEBUG_ERROR_PRINT("Internal leaf is NULL");
	return ;
	}

	node->right = son_right->left;
	son_right->left = node;
	node->parent = son_right;

	// Handle other child/parent pointers.
	if (node->right != NULL)
	node->right->parent = node;

	// Initially node could be the root.
	if (parent != NULL)
	{
	if (node == parent->left)
	parent->left = son_right;
	else if (node == parent->right)
	parent->right = son_right;
	}
	son_right->parent = parent;*/
}

void	tree_rot_right(t_rbt *node)
{
	t_rbt	*old_root = node;

	t_rbt	*parent;
	t_rbt	*new_root;

	parent = tree_parent(old_root);
	new_root = old_root->left;
	old_root->left = new_root->right;
	new_root->right = old_root;
	old_root->parent = new_root;

	if (old_root->left != NULL)
		old_root->left->parent = old_root;

	if (parent != NULL)
	{
		if (parent->left == old_root)
			parent->left = new_root;
		else
			parent->right = new_root;
		new_root->parent = parent;

	}
	else
		new_root->parent = NULL;

	/*t_rbt* son_left = node->left;
	  t_rbt* parent = tree_parent(node);

	// Since the leaves of a red-black tree are empty,
	// they cannot become internal nodes.
	if(son_left == NULL)
	{
	DEBUG_ERROR_PRINT("Internal leaf is NULL");
	return ;
	}

	node->left = son_left->right;
	son_left->right = node;
	node->parent = son_left;

	// Handle other child/parent pointers.
	if (node->left != NULL)
	node->left->parent = node;

	// Initially node could be the root.
	if (parent != NULL)
	{
	if (node == parent->left)
	parent->left = son_left;
	else if (node == parent->right)
	parent->right = son_left;
	}
	son_left->parent = parent;*/
}

/*
 * 	Recoloration
 */

void		tree_recoloring(t_rbt *node)
{
	if (node->parent == NULL)
		node->color = BLACK;
	else if (node->parent->color != BLACK)
	{
		if (tree_uncle(node)->color == RED)
		{
			node->parent->color = BLACK;
			tree_uncle(node)->color = BLACK;

		}
	}
}

/*
 * 	Tree expansion / deletion
 */

void		tree_insert_recurse(t_rbt *root, t_rbt *n)
{
	// Recursively descend the tree until a leaf is found.
	if (root != NULL)
	{
		if (n->key < root->key)
		{
			if (root->left != NULL)
			{
				tree_insert_recurse(root->left, n);
				return;
			}
			else
			{
				root->left = n;
			}
		}
		else
		{ // n->key >= root->key
			if (root->right != NULL)
			{
				tree_insert_recurse(root->right, n);
				return;
			}
			else
			{
				root->right = n;
			}
		}
	}

	// Insert new Node n.
	n->parent = root;
	n->left = NULL;
	n->right = NULL;
	n->color = RED;
}

void		tree_insert_recurse_func(t_rbt *root, t_rbt *n, t_rbt_compare *func)
{
	// Recursively descend the tree until a leaf is found.
	if (root != NULL)
	{
		if (func(root->content, n->content) > 0)
		{
			if (root->left != NULL)
			{
				tree_insert_recurse_func(root->left, n, func);
				return;
			}
			else
			{
				root->left = n;
			}
		}
		else
		{ // n->key >= root->key
			if (root->right != NULL)
			{
				tree_insert_recurse_func(root->right, n, func);
				return;
			}
			else
			{
				root->right = n;
			}
		}
	}

	// Insert new Node n.
	n->parent = root;
	n->left = NULL;
	n->right = NULL;
	n->color = RED;
}

void		tree_insert_case_1(t_rbt *n)
{
	n->color = BLACK;
}

void		tree_insert_case_2(t_rbt *n)
{
	// Do nothing since tree is still valid.
	(void)n;
	return;
}

void		tree_insert_repair(t_rbt *n);
void		tree_insert_case_3(t_rbt *n)
{
	tree_parent(n)->color = BLACK;
	tree_uncle(n)->color = BLACK;
	tree_grand_parent(n)->color = RED;
	tree_insert_repair(tree_grand_parent(n));
}

void		tree_insert_case_4(t_rbt *n)
{
	t_rbt *p = tree_parent(n);
	t_rbt *g = tree_grand_parent(n);

	if (n == p->right && p == g->left)
	{
		tree_rot_left(p);
		n = n->left;
	}
	else if (n == p->left && p == g->right)
	{
		tree_rot_right(p);
		n = n->right;
	}

	p = tree_parent(n);
	g = tree_grand_parent(n);
	if (n == p->left)
	{
		tree_rot_right(g);
	}
	else
	{
		tree_rot_left(g);
	}
	p->color = BLACK;
	g->color = RED;
}

void		tree_insert_repair(t_rbt *n)
{
	if (tree_parent(n) == NULL)
	{
		tree_insert_case_1(n);
	}
	else if (tree_parent(n)->color == BLACK)
	{
		tree_insert_case_2(n);
	}
	else if (tree_uncle(n) != NULL && tree_uncle(n)->color == RED)
	{
		tree_insert_case_3(n);
	}
	else
	{
		tree_insert_case_4(n);
	}
}

t_rbt		*tree_insert(t_rbt *root, void* content, int key)
{
	t_rbt	*n = tree_new_node(content);
	n->key = key;
	// Insert new Node into the current tree.
	//tree_inorder(n);

	tree_insert_recurse(root, n);

	// Repair the tree in case any of the red-black properties have been violated.
	tree_insert_repair(n);

	// Find the new root to return.
	root = tree_root(n);
	return root;
}

t_rbt		*tree_insert_func(t_rbt *root, void* content, t_rbt_compare *func)
{
	t_rbt	*n = tree_new_node(content);
	n->key = 0;
	// Insert new Node into the current tree.
	//tree_inorder(n);

	tree_insert_recurse_func(root, n, func);

	// Repair the tree in case any of the red-black properties have been violated.
	tree_insert_repair(n);

	// Find the new root to return.
	root = tree_root(n);
	return root;
}

/*
 *	Search
 */


/*
 *	Print
 */

void		tree_str(t_rbt *root)
{
	if (root != NULL)
	{
		if (root->color == RED)
			ft_printf("R%~{255;150;150}%d%~{}", root->key);
		else
			ft_printf("B%~{150;150;255}%d%~{}", root->key);
	}
	else
		ft_printf("null");
}

int			tree_inorder(t_rbt *root, t_rbt_inorder *func)
{
	int		value = 0;

	if (root != NULL)
	{
		value += tree_inorder(root->left, func);
		value += func(root);
		value += tree_inorder(root->right, func);
	}
	return value;
}

int		print_node_info(t_rbt *root)
{
	if (root != NULL)
	{
		ft_printf("P ");
		tree_str(root->parent);
		ft_printf("\t");
		tree_str(root);
		ft_printf("\tl ");
		tree_str(root->left);
		ft_printf("\tr ");
		tree_str(root->right);
		ft_printf("\n");
		return (1);
	}
	else
		ft_printf("Null node\n");
	return (0);
}

void	tree_simple_print(t_rbt *root)
{
	tree_inorder(root, &print_node_info);
}

#define NB_OF_SPACE		7

void	padding_before(t_rbt *node, size_t space)
{
	t_rbt	*parent;
	size_t 		i;

	i = 0;
	parent = tree_parent(node);
	while (i < space)
	{
		printf(" ");
		i++;
	}
	if (parent != NULL)
		(parent->left == node) ? printf("╰─ ") : printf("╭─ ");
}

void	padding_after(t_rbt *node)
{
	size_t 		i;
	size_t		padding;

	if (node->left != NULL || node->right != NULL)
	{
		padding = NB_OF_SPACE - ft_nb_len(node->key, 10) - 4;
		padding = NB_OF_SPACE - 3 - 4;
		i = 0;
		while (i < padding)
		{
			printf("─");
			i++;
		}
		if (tree_root(node) == node)
			printf("───");
		printf("┤");
	}
	printf("\n");
}

void	tree_print_elem(t_rbt *node)
{
	void	*content = (node->content);

	if (node->color == RED)
		printf("\033[31m");
	else
		printf("\033[34m");
	printf("%p \033[00m", content);
}


void	tree_print(t_rbt *node, size_t deep)
{
	if (node == NULL)
	{
		//padding_before(node, (deep * NB_OF_SPACE));
		//printf("\033[34mx \033[00m");
		return ;
	}
	tree_print(node->right, deep + 1);

	padding_before(node, (deep * NB_OF_SPACE));
	tree_print_elem(node);
	padding_after(node);

	tree_print(node->left, deep + 1);
}
