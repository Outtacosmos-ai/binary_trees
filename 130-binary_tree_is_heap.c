#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Tree to measure
 * Return: Size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * is_complete - Checks if tree is complete
 * @tree: Pointer to root
 * @index: Node index
 * @size: Tree size
 * Return: 1 if complete, 0 if not
 */
int is_complete(const binary_tree_t *tree, int index, int size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
		is_complete(tree->right, 2 * index + 2, size));
}

/**
 * check_max_heap - Checks max heap properties
 * @tree: Pointer to root
 * Return: 1 if valid max heap, 0 if not
 */
int check_max_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->right)
		return (tree->n >= tree->left->n);

	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
		return (check_max_heap(tree->left) && check_max_heap(tree->right));

	return (0);
}

/**
 * binary_tree_is_heap - Checks if binary tree is valid Max Binary Heap
 * @tree: Pointer to root
 * Return: 1 if tree is valid Max Binary Heap, 0 if not
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);

	if (is_complete(tree, 0, size) && check_max_heap(tree))
		return (1);
	return (0);
}
