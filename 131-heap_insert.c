#include "binary_trees.h"

/**
	* swap - Swaps two integers
	* @a: First integer
	* @b: Second integer
	*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
	* size - Measures size of binary tree
	* @tree: Pointer to root
	* Return: Size of tree
	*/
size_t size(const binary_tree_t *tree)
{
	if (!tree)
	return (0);
	return (1 + size(tree->left) + size(tree->right));
}

/**
	* insert_node - Inserts node at proper position
	* @root: Root of heap
	* @level: Level to insert node
	* @pos: Position at level
	* @node: Node to insert
	* Return: 1 if inserted, 0 if not
	*/
int insert_node(heap_t *root, size_t level, size_t pos, heap_t *node)
{
	if (level == 1)
	{
	if (pos == 0 && !root->left)
	{
	root->left = node;
	node->parent = root;
	return (1);
	}
	if (pos == 1 && !root->right)
	{
	root->right = node;
	node->parent = root;
	return (1);
	}
	return (0);
	}

	if (root->left && insert_node(root->left, level - 1, pos / 2, node))
	return (1);
	if (root->right && insert_node(root->right, level - 1, pos / 2, node))
	return (1);
	return (0);
}

/**
	* heap_insert - Inserts value in Max Binary Heap
	* @root: Double pointer to root
	* @value: Value to insert
	* Return: Pointer to inserted node
	*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	size_t tree_size, level, pos;
	int inserted = 0;

	if (!root)
	return (NULL);

	node = binary_tree_node(NULL, value);
	if (!node)
	return (NULL);

	if (!*root)
	{
	*root = node;
	return (node);
	}

	tree_size = size(*root);
	for (level = 1; !inserted; level++)
	{
	for (pos = 0; pos < (size_t)(1 << (level - 1)) && !inserted; pos++)
	if (tree_size < (size_t)((1 << level) - 1))
	inserted = insert_node(*root, level, pos, node);
	}

	while (node->parent && node->n > node->parent->n)
	{
	swap(&node->n, &node->parent->n);
	node = node->parent;
	}

	return (node);
}
