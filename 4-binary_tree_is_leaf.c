#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf in a binary tree.
 * @node: Pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, otherwise 0.
 *
 * Description: A leaf node is a node that has no children.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	/* Check if the node has no children */
	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}
