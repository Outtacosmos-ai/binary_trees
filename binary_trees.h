#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/* Function prototypes */
size_t tree_size(const binary_tree_t *tree);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
heap_t *array_to_heap(int *array, size_t size);
heap_t *heap_insert(heap_t **root, int value); /* Insert value into Max Binary Heap */
heap_t *create_new_node(heap_t *parent, int value); /* Create a new node */
heap_t *find_insertion_parent(heap_t *root, size_t size); /* Find insertion point */
void bubble_up(heap_t *node); /* Maintain heap property after insertion */

int heap_extract(heap_t **root);
int binary_tree_is_heap(const binary_tree_t *tree);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *rebalance(avl_t *root); /* This function is called in avl_remove */
size_t binary_tree_height(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
void binary_tree_delete(binary_tree_t *tree);

#endif /* BINARY_TREES_H */
