#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a given node is the root of a binary tree.
 * @node: Pointer to the node to check.
 *
 * Return: 1 if the node is a root, otherwise 0.
 *
 * Description: A root node is a node that has no parent.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	/* Ensure the node is valid and has no parent */
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
