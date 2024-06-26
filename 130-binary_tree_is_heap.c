#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    /* Check if tree is a complete tree */
    if (!binary_tree_is_complete(tree, 0, binary_tree_size(tree)))
        return 0;

    /* Check if tree satisfies the Max Binary Heap property */
    return is_max_heap(tree);
}

/**
 * binary_tree_size - Computes the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @size: Size of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
    if (tree == NULL)
        return 1;

    if (index >= size)
        return 0;

    return (binary_tree_is_complete(tree->left, 2 * index + 1, size) &&
            binary_tree_is_complete(tree->right, 2 * index + 2, size));
}

/**
 * is_max_heap - Checks if a binary tree satisfies the Max Binary Heap property
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree satisfies the Max Binary Heap property, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 1;

    if (tree->left && tree->left->n > tree->n)
        return 0;

    if (tree->right && tree->right->n > tree->n)
        return 0;

    return is_max_heap(tree->left) && is_max_heap(tree->right);
}

