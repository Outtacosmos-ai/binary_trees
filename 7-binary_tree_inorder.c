#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree using in-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Description: In in-order traversal, the left subtree is visited first,
 *              followed by the current node, and then the right subtree.
 *              The function func is called with the value of each node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Ensure both tree and func are valid */
	if (tree == NULL || func == NULL)
		return;

	/* Recursively traverse the left subtree */
	binary_tree_inorder(tree->left, func);

	/* Process the current node */
	func(tree->n);

	/* Recursively traverse the right subtree */
	binary_tree_inorder(tree->right, func);
}
