#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 *
 * Return: a pointer to the root node of the created Binary Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);  /* Check for invalid input */
	for (i = 0; i < size; i++)
	{
		if (!heap_insert(&root, array[i]))
			return (NULL);  /* Return NULL if insertion fails */
	}

	return (root);
}
