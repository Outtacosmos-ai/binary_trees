#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as the left-child of
 *                           a given parent node in a binary tree.
 * @parent: Pointer to the node where the new left-child will be inserted.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or memory allocation fails - NULL.
 *         Otherwise, returns a pointer to the newly created node.
 *
 * Description: If the parent node already has a left-child, the new node
 *              will replace it, and the old left-child becomes the left-child
 *              of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check if the parent node is NULL */
	if (parent == NULL)
		return (NULL);

	/* Create the new node and check if memory allocation succeeded */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* If the parent already has a left child, update the pointers */
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}

	/* Set the new node as the left child of the parent */
	parent->left = new_node;

	return (new_node);  /* Return the pointer to the newly created node */
}
