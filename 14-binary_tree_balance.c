#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0. Otherwise, return the balance factor.
 *         The balance factor is the difference between the height of the
 *         left and right subtrees.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/*
	 * If the tree is not NULL, calculate the balance factor.
	 */
	if (tree)
	{
		/*
		 * The balance factor is the difference between the height of the left
		 * and right subtrees.
		 */
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}

	/*
	 * If the tree is NULL, return 0.
	 */
	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, return 0. Otherwise, return the height of the tree.
 *         The height of a tree is the number of edges on the longest path
 *         from the root to a leaf node.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/*
	 * If the tree is not NULL, calculate the height of the left and right
	 * subtrees.
	 */
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		/*
		 * Recursively calculate the height of the left and right subtrees.
		 */
		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		/*
		 * Return the larger of the left and right subtree heights.
		 */
		return ((left_height > right_height) ? left_height : right_height);
	}

	/*
	 * If the tree is NULL, return 0.
	 */
	return (0);
}
