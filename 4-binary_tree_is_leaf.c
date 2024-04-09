#include "binary_trees.h"

/**
 * binary_tree_is_leaf - A function that checks if a node is a leaf
 * @node: A Pointer to the node to check
 *
 * Return: 1 if node is a leaf 0 otherwise
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* Check if the node is NULL or has children */
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1); /* Node is a leaf */
}
