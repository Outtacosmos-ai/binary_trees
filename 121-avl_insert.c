#include "binary_trees.h"

/**
 * avl_insert_recursive - Recursively inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @parent: Parent node of the current node
 * @new_node: Double pointer to store the new node
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the new root, or NULL on failure
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value)
{
	int balance;

	if (!*tree)
		return (*new_node = binary_tree_node(parent, value));

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left,
				*tree, new_node, value);
		if (!(*tree)->left)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right,
				*tree, new_node, value);
		if (!(*tree)->right)
			return (NULL);
	}
	else
		return (*tree);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, NULL, &new_node, value);
	return (new_node);
}
