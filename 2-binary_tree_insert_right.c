#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right child
 *                            of a binary tree.
 * @parent: Pointer to the node to insert the right child in.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the new node, or NULL if parent is NULL
 *         or memory allocation fails.
 *
 * Description: If the parent already has a right child, the new
 *              node takes its place, and the old right child
 *              becomes the right child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Validate input */
	if (parent == NULL)
		return (NULL);

	/* Create a new binary tree node */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* Handle the existing right child, if present */
	if (parent->right != NULL)
	{
		/* Link the old right child to the new node */
		new_node->right = parent->right;

		/* Update the parent pointer of the old child */
		parent->right->parent = new_node;
	}

	/* Set the new node as the right child of the parent */
	parent->right = new_node;

	return (new_node);
}
