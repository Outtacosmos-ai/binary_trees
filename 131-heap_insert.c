#include "binary_trees.h"

/* Function Declarations */
heap_t *find_empty_slot(heap_t *current, int leaves_count, int tree_level);
void heapify_up(heap_t *new_node);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *current, *new_node;
	int tree_size, leaves_count, subtree_size, tree_level;

	if (!root)
		return (NULL);

	/* If the root is NULL, create the first node */
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	current = *root;
	tree_size = binary_tree_size(current);
	leaves_count = tree_size;

	/* Determine the level of the last leaf node */
	for (tree_level = 0, subtree_size = 1; leaves_count >= subtree_size;
	     subtree_size *= 2, tree_level++)
		leaves_count -= subtree_size;

	/* Traverse the tree to find the first empty slot */
	current = find_empty_slot(current, leaves_count, tree_level);

	/* Create a new node to insert into the heap */
	new_node = binary_tree_node(current, value);

	/* Attach the new node to the correct child position */
	leaves_count & 1 ? (current->right = new_node) : (current->left = new_node);

	/* Perform heapify operation to maintain Max-Heap property */
	heapify_up(new_node);

	/* Return the pointer to the newly inserted node */
	return (new_node);
}

/**
 * find_empty_slot - Finds the first empty slot based on binary representation
 * @current: The current node being examined
 * @leaves_count: The number of leaves in the tree
 * @tree_level: The current level in the tree
 *
 * Return: A pointer to the node representing the empty slot
 */
heap_t *find_empty_slot(heap_t *current, int leaves_count, int tree_level)
{
	/* Traverse tree based on binary representation of the number of leaves */
	for (int bit_mask = 1 << (tree_level - 1); bit_mask != 1; bit_mask >>= 1)
	{
		if (leaves_count & bit_mask)
			current = current->right;
		else
			current = current->left;
	}

	return (current);
}

/**
 * heapify_up - Maintains the Max-Heap property by swapping with parent
 * @new_node: The newly inserted node
 *
 * Return: Nothing
 */
void heapify_up(heap_t *new_node)
{
	heap_t *parent_node;
	int tmp;

	/* Swap values with parent if new node is greater */
	parent_node = new_node;
	while (parent_node->parent && (parent_node->n > parent_node->parent->n))
	{
		/* Swap the values between the node and its parent */
		tmp = parent_node->n;
		parent_node->n = parent_node->parent->n;
		parent_node->parent->n = tmp;
		parent_node = parent_node->parent;
	}
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: The tree to measure the size of
 *
 * Return: The size of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* Recursively calculate the total number of nodes in the tree */
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
