#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *temp1, *temp2;

	if (!first || !second)
		return (NULL);

	temp1 = (binary_tree_t *)first;
	while (temp1)
	{
		temp2 = (binary_tree_t *)second;
		while (temp2)
		{
			if (temp1 == temp2)
				return (temp1);
			temp2 = temp2->parent;
		}
		temp1 = temp1->parent;
	}
	return (NULL);
}
