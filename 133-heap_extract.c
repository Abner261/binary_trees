#include "binary_trees.h"

/**
 * get_tree_height - Get the height of the tree
 * @root: Pointer to the root node of the tree
 * Return: Height of the tree
 */
size_t get_tree_height(heap_t *root)
{
    if (root == NULL)
        return (0);
    return (1 + get_tree_height(root->left));
}

/**
 * get_last_node - Get the last node of the heap
 * @root: Pointer to the root node of the tree
 * Return: Pointer to the last node of the tree
 */
heap_t *get_last_node(heap_t *root)
{
    if (root == NULL)
        return (NULL);
    if (get_tree_height(root->left) > get_tree_height(root->right))
        return (get_last_node(root->left));
    if (get_tree_height(root->left) == get_tree_height(root->right))
    {
        if (root->left == NULL || root->right == NULL)
            return (root);
        return (get_last_node(root->right));
    }
    return (get_last_node(root->right));
}

/**
 * heapify_down - Heapify down the tree
 * @root: Pointer to the root node of the tree
 */
void heapify_down(heap_t **root)
{
    heap_t *node = *root;
    heap_t *child;

    while (1)
    {
        child = NULL;
        if (node->left && node->left->n > node->n)
            child = node->left;
        if (node->right && node->right->n > node->n &&
            (!child || node->right->n > child->n))
            child = node->right;
        if (!child)
            break;
        if (!node->parent)
            *root = child;
        if (child == node->left)
            binary_tree_rotate_right(node);
        else
            binary_tree_rotate_left(node);
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node, *parent;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    last_node = get_last_node(*root);

    if (*root == last_node)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    last_node->parent = NULL;
    last_node->left = (*root)->left;
    last_node->right = (*root)->right;
    if (last_node->left)
        last_node->left->parent = last_node;
    if (last_node->right)
        last_node->right->parent = last_node;

    parent = last_node->parent;
    free(*root);
    *root = last_node;

    if (parent && parent->n < last_node->n)
        heapify_down(root);

    return (value);
}

