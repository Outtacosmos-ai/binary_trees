#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves of.
 *
 * Return: The number of leaves in the tree, or 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf_count = 0;

	/* If the tree is not NULL */
	if (tree)
	{
		/* A leaf is a node with no children */
		if (!tree->left && !tree->right)
		{
			leaf_count = 1;
		}
		else
		{
			/* Recursively count leaves in the left and right subtrees */
			leaf_count += binary_tree_leaves(tree->left);
			leaf_count += binary_tree_leaves(tree->right);
		}
	}

	/* Return the total count of leaves */
	return (leaf_count);
}
