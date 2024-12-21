#include "binary_trees.h"

/**
 * heap_size - Measures the size of a binary tree
 * @tree: Pointer to root
 * Return: Size of the tree, 0 if NULL
 */
size_t heap_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (heap_size(tree->left) + heap_size(tree->right) + 1);
}

/**
 * sift_up - Moves a value up in the heap
 * @node: Pointer to the node to move
 * Return: Pointer to the final position of the node
 */
heap_t *sift_up(heap_t *node)
{
	int temp;

	if (!node || !node->parent)
		return (node);

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	return (node);
}

/**
 * get_parent - Finds the parent node for insertion
 * @root: Pointer to root
 * @size: Size of the heap
 * Return: Pointer to parent node
 */
heap_t *get_parent(heap_t *root, size_t size)
{
	heap_t *parent = root;
	size_t bit;

	/* Traverse from the highest bit down to the lowest */
	for (bit = size / 2; bit > 0; bit /= 2)
	{
		if (size & bit)
			parent = parent->right;
		else
			parent = parent->left;

		if (!parent)
			break;
	}

	return (parent);
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to root
 * @value: Value to insert
 * Return: Pointer to inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	size_t size;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = heap_size(*root);
	parent = get_parent(*root, size + 1);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (size & 1)
		parent->right = new_node;
	else
		parent->left = new_node;

	return (sift_up(new_node));
}
