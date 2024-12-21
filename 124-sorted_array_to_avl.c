#include "binary_trees.h"

/**
 * aux_sorted_array_to_avl - Auxiliary function to build an AVL tree
 * @array: Input array
 * @start: Starting index
 * @end: Ending index
 * @parent: Parent node
 * Return: Pointer to the root
 */
avl_t *aux_sorted_array_to_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = aux_sorted_array_to_avl(array, start, mid - 1, root);
	root->right = aux_sorted_array_to_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Input array
 * @size: Size of array
 * Return: Pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (aux_sorted_array_to_avl(array, 0, size - 1, NULL));
}
