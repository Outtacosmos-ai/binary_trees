#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Description: This function performs post-order traversal of the binary tree,
 *              which involves visiting the left subtree, the right subtree,
 *              and then the current node. It calls the function `func` on each
 *              node's value.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		/* Traverse the left subtree */
		binary_tree_postorder(tree->left, func);

		/* Traverse the right subtree */
		binary_tree_postorder(tree->right, func);

		/* Call the function on the current node's value */
		func(tree->n);
	}
}
