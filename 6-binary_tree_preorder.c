#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Description: In pre-order traversal, the current node is visited first,
 *              followed by the left subtree, then the right subtree.
 *              The function func is called with the value of each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Ensure both tree and func are valid */
	if (tree == NULL || func == NULL)
		return;

	/* Process the current node */
	func(tree->n);

	/* Recursively traverse the left and right subtrees */
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
