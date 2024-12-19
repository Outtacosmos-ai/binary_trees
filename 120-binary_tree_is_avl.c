#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>  // For abs()


/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_avl_util - Utility function to check if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * @min: The minimum value a node can have
 * @max: The maximum value a node can have
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int is_avl_util(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_avl_util(tree->left, min, tree->n) &&
			is_avl_util(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_avl_util(tree, INT_MIN, INT_MAX));
}
