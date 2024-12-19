#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	/* If tree is not NULL, recursively count the size */
	if (tree)
	{
		/* Start by counting the current node */
		size = 1;

		/* Recurse to the left and right children */
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}

	/* Return the total size */
	return (size);
}
