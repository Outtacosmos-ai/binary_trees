#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: The number of nodes with at least one child, or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node_count = 0;

	/* If the tree is not NULL */
	if (tree)
	{
		/* A node with at least one child has either a left or right child */
		if (tree->left || tree->right)
		{
			node_count = 1;
		}

		/* Recursively count nodes in the left and right subtrees */
		node_count += binary_tree_nodes(tree->left);
		node_count += binary_tree_nodes(tree->right);
	}

	/* Return the total count of nodes with at least one child */
	return (node_count);
}
