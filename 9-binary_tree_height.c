#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0. Otherwise, it returns the
 *         height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		/* Calculate the height of the left subtree */
		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;

		/* Calculate the height of the right subtree */
		right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		/* Return the maximum height between the left and right subtrees */
		return (left_height > right_height ? left_height : right_height);
	}

	/* Return 0 if the tree is NULL */
	return (0);
}
