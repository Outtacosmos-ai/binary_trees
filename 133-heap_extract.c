#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer    
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heap_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t heap_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * get_last_node - Gets the last level-order node of a heap
 * @root: Pointer to heap root
 * Return: Pointer to last node
 */
heap_t *get_last_node(heap_t *root)
{
    size_t size = heap_size(root);
    size_t bit;
    heap_t *node = root;

    for (bit = 1UL << (sizeof(size_t) * 8 - 2); bit > 1; bit >>= 1)
    {
        if (size & bit)
            node = node->right;
        else
            node = node->left;

        if (!node)
            break;
    }

    return (node);
}

/**
 * sift_down - Fixes the heap after extraction
 * @root: Pointer to heap root
 */
void sift_down(heap_t *root)
{
    heap_t *node = root, *child;

    while (1)
    {
        if (!node->left)
            break;

        child = node->left;
        if (node->right && node->right->n > node->left->n)
            child = node->right;

        if (node->n >= child->n)
            break;

        swap(&node->n, &child->n);
        node = child;
    }
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Double pointer to root
 * Return: Value stored in the root node
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node, *heap_root;

    if (!root || !*root)
        return (0);

    heap_root = *root;
    value = heap_root->n;

    if (!heap_root->left && !heap_root->right)
    {
        free(heap_root);
        *root = NULL;
        return (value);
    }

    last_node = get_last_node(heap_root);

    heap_root->n = last_node->n;
    if (last_node->parent->right == last_node)
        last_node->parent->right = NULL;
    else
        last_node->parent->left = NULL;

    free(last_node);
    sift_down(heap_root);

    return (value);
}

