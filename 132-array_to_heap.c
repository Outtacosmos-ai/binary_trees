#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 * @array: Pointer to first element of array
 * @size: Number of elements in array
 * Return: Pointer to root node of created Binary Heap
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
