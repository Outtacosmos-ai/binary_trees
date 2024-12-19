#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, the function returns 0. Otherwise, it returns the
 *         depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
	{
		/* Recurse to the parent node and increment depth */
		return (1 + binary_tree_depth(tree->parent));
	}

	/* Return 0 if the tree or parent is NULL */
	return (0);
}
