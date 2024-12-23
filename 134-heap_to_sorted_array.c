#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to root node of heap
 * @size: Address to store size of array
 * Return: Pointer to array sorted in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t heap_size;
	size_t i;

	if (!heap || !size)
		return (NULL);

	heap_size = binary_tree_size(heap);
	*size = heap_size;

	array = malloc(heap_size * sizeof(int));
	if (!array)
		return (NULL);

	for (i = 0; i < heap_size; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
