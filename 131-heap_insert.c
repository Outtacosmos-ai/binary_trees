#include "binary_trees.h"

/**
 * get_size - Gets size of binary tree
 * @tree: Pointer to tree
 * Return: Size of tree
 */
size_t get_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_size(tree->left) + get_size(tree->right));
}

/**
 * heap_insert - Inserts value in Max Binary Heap
 * @root: Double pointer to root
 * @value: Value to store
 * Return: Created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *current;
	int tmp;
	size_t size, i;

	if (!root)
		return (NULL);
	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	current = *root;
	size = get_size(*root);
	for (i = 1; i <= size / 2; i = i * 2)
	{
		if ((size + 1) & i)
			current = current->right;
		else
			current = current->left;
		if (!current)
			break;
	}

	new = binary_tree_node(current, value);
	if (!new)
		return (NULL);

	if (!current->left)
		current->left = new;
	else
		current->right = new;

	while (new->parent && new->n > new->parent->n)
	{
		tmp = new->n;
		new->n = new->parent->n;
		new->parent->n = tmp;
		new = new->parent;
	}
	return (new);
}
