#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_min - Finds the minimum value in a BST
 * @root: Pointer to the root node of the BST
 * Return: Pointer to the node with the minimum value
 */
bst_t *find_min(bst_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 * Return: Pointer to the new root node of the tree
 *         after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
