#include "binary_trees.h"
#include "limits.h"

/* Function prototypes */
size_t calculate_height(const binary_tree_t *tree);
int validate_avl_tree(const binary_tree_t *tree, int min_value, int max_value);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * calculate_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, returns 0. Otherwise, returns the height
 *         of the tree.
 */
size_t calculate_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left_height = 0, right_height = 0;

		left_height = (tree->left != NULL) ? 1 + calculate_height(tree->left) : 1;
		right_height = (tree->right != NULL) ? 1 + calculate_height(tree->right) : 1;

		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

/**
 * validate_avl_tree - Recursively checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min_value: The smallest value allowed for the current node.
 * @max_value: The largest value allowed for the current node.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int validate_avl_tree(const binary_tree_t *tree, int min_value, int max_value)
{
	size_t left_height, right_height, height_diff;

	if (tree != NULL)
	{
		/* Ensure the current node's value is within the allowed range */
		if (tree->n < min_value || tree->n > max_value)
			return (0);

		/* Calculate the height of the left and right subtrees */
		left_height = calculate_height(tree->left);
		right_height = calculate_height(tree->right);

		/*
		 * Check the balance factor:
		 * difference between left and right subtree heights
		 */
		height_diff = (left_height > right_height) ? left_height - right_height :
								(right_height - left_height);
		if (height_diff > 1)
			return (0);

		/* Recursively check the left and right subtrees */
		return (validate_avl_tree(tree->left, min_value, tree->n - 1) &&
			validate_avl_tree(tree->right, tree->n + 1, max_value));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	/* If the tree is empty, it's not an AVL tree */
	if (tree == NULL)
		return (0);

	/* Start the validation with the entire range of integer values */
	return (validate_avl_tree(tree, INT_MIN, INT_MAX));
}
