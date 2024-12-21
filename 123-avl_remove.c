#include "binary_trees.h"
#include <stdlib.h>


/**
	* bal - Measures the balance factor of an AVL tree and rebalances it
	* @tree: Double pointer to the root of the AVL tree
	* Return: None
	*/
void bal(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
	return;

	/* Recur on left and right subtrees */
	bal(&(*tree)->left);
	bal(&(*tree)->right);

	/* Get balance factor */
	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	/* Rebalance if necessary */
	if (balance_factor > 1)
	*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
	*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
	* successor - Finds the next successor (minimum node in right subtree)
	* @node: Pointer to the node to check
	* Return: The minimum value in the subtree
	*/
int successor(bst_t *node)
{
	if (node == NULL)
	return (0);

	if (node->left == NULL)
	return (node->n);

	return (successor(node->left));
}

/**
	* remove_type - Removes a node depending on its children
	* @node: Pointer to the node to remove
	* Return: 0 if the node has no children; otherwise, the new value of the node
	*/
int remove_type(bst_t *node)
{
	int new_value = 0;

	if (!node->left && !node->right) /* No children */
	{
	if (node->parent->right == node)
	node->parent->right = NULL;
	else
	node->parent->left = NULL;
	free(node);
	return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left)) /* One child */
	{
	if (!node->left)
	{
	if (node->parent->right == node)
	node->parent->right = node->right;
	else
	node->parent->left = node->right;
	node->right->parent = node->parent;
	}
	else
	{
	if (node->parent->right == node)
	node->parent->right = node->left;
	else
	node->parent->left = node->left;
	node->left->parent = node->parent;
	}
	free(node);
	return (0);
	}
	else /* Two children */
	{
	new_value = successor(node->right);
	node->n = new_value;
	return (new_value);
	}
}

/**
	* bst_remove - Removes a node with a specific value from a BST
	* @root: Pointer to the root of the BST
	* @value: Value of the node to remove
	* Return: Pointer to the new root of the tree
	*/
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
	return (NULL);

	if (value < root->n)
	bst_remove(root->left, value);
	else if (value > root->n)
	bst_remove(root->right, value);
	else
	{
	type = remove_type(root);
	if (type != 0)
	bst_remove(root->right, type);
	}

	return (root);
}

/**
	* avl_remove - Removes a node with a specific value from an AVL tree
	* @root: Pointer to the root of the AVL tree
	* @value: Value of the node to remove
	* Return: Pointer to the new root of the AVL tree
	*/
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *modified_root = (avl_t *)bst_remove((bst_t *)root, value);

	if (modified_root == NULL)
	return (NULL);

	/* Rebalance the AVL tree */
	bal(&modified_root);

	return (modified_root);
}
