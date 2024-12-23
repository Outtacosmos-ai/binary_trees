#include "binary_trees.h"
/**
 * swap_nodes - Swaps two nodes in a binary tree
 * @a: First node
 * @b: Second node
 */
void swap_nodes(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}

/**
	* binary_tree_size - measures the size of a binary tree
	* @tree: pointer to the root node of the tree to measure the size
	* Return: Size of the tree, 0 if tree is NULL
	*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
	* get_parent - finds the parent node for the new insertion
	* @root: pointer to the root node
	* @index: index where the new node should be inserted
	* Return: pointer to the parent node
	*/
heap_t *get_parent(heap_t *root, size_t index)
{
	size_t parent_idx = (index - 1) / 2;
	size_t current = 0;
	heap_t *parent = root;

	while (current < parent_idx)
	{
		if ((parent_idx - 1) / 2 >= current)
			parent = parent->left;
		else
			parent = parent->right;
		current = (current * 2) + 1;
	}
	return (parent);
}

/**
	* heap_insert - inserts a value into a Max Binary Heap
	* @root: double pointer to the root node of the Heap
	* @value: value to store in the node to be inserted
	* Return: pointer to the inserted node, or NULL on failure
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
	parent = get_parent(*root, size);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (size % 2)
		parent->right = new_node;
	else
		parent->left = new_node;

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		swap_nodes(new_node, new_node->parent);
		new_node = new_node->parent;
	}

	return (new_node);
}
