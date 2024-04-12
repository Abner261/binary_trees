#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Pointer to a pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node = NULL;

    if (tree == NULL)
        return (NULL);

    /* Perform standard BST insertion */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
    }
    else
    {
        /* Value already exists, return NULL */
        return (NULL);
    }

    /* Update height of this ancestor node */
    (*tree)->height = 1 + max(binary_tree_height((*tree)->left),
                              binary_tree_height((*tree)->right));

    /* Check balance factor to determine rotation */
    int balance = binary_tree_balance(*tree);

    /* Left Left Case */
    if (balance > 1 && value < (*tree)->left->n)
        return binary_tree_rotate_right(*tree);

    /* Right Right Case */
    if (balance < -1 && value > (*tree)->right->n)
        return binary_tree_rotate_left(*tree);

    /* Left Right Case */
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return binary_tree_rotate_right(*tree);
    }

    /* Right Left Case */
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return binary_tree_rotate_left(*tree);
    }

    return (*tree);
}

