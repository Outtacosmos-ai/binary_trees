#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size - Measures the total number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: The total number of nodes in the tree, or 0 if tree is NULL.
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (!tree)
		return (0);

	/* Recursively calculate the size of the left subtree */
	if (tree->left)
		left_size = tree_size(tree->left);

	/* Recursively calculate the size of the right subtree */
	if (tree->right)
		right_size = tree_size(tree->right);

	/* Return the sum of left and right subtree sizes plus the current node */
	return (left_size + right_size + 1);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap into a sorted array.
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the resulting array.
 *
 * Return: Pointer to an array sorted in descending order, or NULL if memory
 * allocation fails.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int index = 0;
	int *sorted_array = NULL;

	if (!heap || !size)
		return (NULL);

	/* Determine the total number of nodes in the heap */
	*size = tree_size(heap);

	/* Allocate memory for the sorted array */
	sorted_array = malloc(sizeof(int) * (*size));
	if (!sorted_array)
		return (NULL);

	/* Extract the maximum element from the heap and store it in the array */
	while (heap)
	{
		sorted_array[index] = heap_extract(&heap);
		index++;
	}

	return (sorted_array);
}
