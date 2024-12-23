#include "binary_trees.h"

/**
	* swap - swaps two integers
	* @a: first integer
	* @b: second integer
	*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
	* binary_tree_size - measures the size of a binary tree
	* @tree: pointer to the root node of the tree to measure the size
	* Return: size of the tree, 0 if tree is NULL
	*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
	* heapify_up - maintains the max heap property by moving a node up
	* @node: pointer to the node to move up
	*/
void heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
	swap(&node->n, &node->parent->n);
	node = node->parent;
	}
}

/**
	* heap_insert - inserts a value in Max Binary Heap
	* @root: double pointer to the root node of the Heap
	* @value: value to store in the node to be inserted
	* Return: pointer to the created node, or NULL on failure
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

	size = binary_tree_size(*root);
	parent = *root;

	while (size > 1)
	{
	if (size % 2 == 0)
	parent = parent->left;
	else
	parent = parent->right;
	size /= 2;
	}

	new_node = binary_tree_node(parent, value);
	if (!new_node)
	return (NULL);

	if (!parent->left)
	parent->left = new_node;
	else
	parent->right = new_node;

	heapify_up(new_node);

	return (new_node);
}
