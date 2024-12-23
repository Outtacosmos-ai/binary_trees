#include "binary_trees.h"
#include <stdlib.h> /* Required for free */

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: Pointer to the root node of the tree to delete.
 *
 * Description: This function recursively deletes all nodes
 *              of a binary tree by performing a post-order traversal.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);
    free(tree);
}
