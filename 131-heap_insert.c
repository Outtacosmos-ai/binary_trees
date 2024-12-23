#include "binary_trees.h"
#include <math.h>  /* Include this for log2() */

/**
 * create_new_node - Creates a new binary tree node.
 * @parent: Pointer to the parent node.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
heap_t *create_new_node(heap_t *parent, int value)
{
	heap_t *new_node = binary_tree_node(parent, value);

	return (new_node);
}

/**
 * binary_tree_size - Calculates the size of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Size of the tree.
 */
size_t binary_tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * find_insertion_parent - Finds the insertion parent in a Max Binary Heap.
 * @root: Pointer to the root node of the tree.
 * @size: Size of the binary tree.
 *
 * Return: Pointer to the parent node for insertion.
 */
heap_t *find_insertion_parent(heap_t *root, size_t size)
{
	heap_t *parent = root;
	size_t path = size + 1;
	size_t mask = 1;

	/* Use log2 to calculate the highest bit */
	while (mask <= size)
	{
		mask <<= 1;
	}

	while (mask > 1)
	{
		mask >>= 1;
		if (path & mask)
			parent = parent->right;
		else
			parent = parent->left;
	}

	return (parent);
}

/**
 * bubble_up - Maintains Max Heap property after insertion.
 * @node: Pointer to the newly inserted node.
 */
void bubble_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new_node;
	size_t size;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = create_new_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);

	parent = find_insertion_parent(*root, size);

	new_node = create_new_node(parent, value);
	if (!new_node)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	bubble_up(new_node);

	return (new_node);
}
