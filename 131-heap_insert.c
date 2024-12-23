#include "binary_trees.h"

/**
 * swap_values - Swaps values of two nodes
 * @a: First node
 * @b: Second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int temp;

	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * get_last_node - Gets the last node position
 * @root: Root node
 * @size: Size of heap
 * Return: Last node position
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t bin;
	size_t mask = 1;

	bin = size;
	mask = mask << (sizeof(size_t) * 8 - 2);

	while (!(bin & mask))
		mask = mask >> 1;

	mask = mask >> 1;
	while (mask && root)
	{
		if (bin & mask)
			root = root->right;
		else
			root = root->left;
		mask = mask >> 1;
	}
	return (root);
}

/**
 * get_size - Gets size of binary tree
 * @root: Root node
 * Return: Size of tree
 */
size_t get_size(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + get_size(root->left) + get_size(root->right));
}

/**
 * heap_insert - Inserts value in Max Binary Heap
 * @root: Double pointer to root
 * @value: Value to store
 * Return: Created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;
	size_t size;

	if (!root)
		return (NULL);
	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	size = get_size(*root);
	parent = get_last_node(*root, size + 1);

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;

	while (new->parent && new->n > new->parent->n)
	{
		swap_values(new, new->parent);
		new = new->parent;
	}
	return (new);
}
