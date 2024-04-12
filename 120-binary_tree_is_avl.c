#include "binary_trees.h"

/**
 * max - Get the maximum of two numbers
 * @a: First number
 * @b: Second number
 * Return: Maximum of a and b
 */

static int max(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * height - Compute the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree
 */

static int height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (-1);
    return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
    int left_height, right_height, balance;

    if (tree == NULL)
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);
    balance = left_height - right_height;

    if (balance > 1 || balance < -1)
        return (0);

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}

