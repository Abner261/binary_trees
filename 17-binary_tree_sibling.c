#include "binary_trees.h"

/**
 * binary_tree_sibling - A function that finds the sibling of a node
 * @node: A Pointer to the node to find the sibling
 *
 * Return: A Pointer to the sibling node, or NULL if no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
		node->parent->left == NULL || node->parent->right == NULL)
	{
		return (NULL); /* Return NULL if node or parent is NULL */
	}

	if (node->parent->left->n == node->n)
	{
		return (node->parent->right);
		/* Return right child if node is the left child */
	}
	else if (node->parent->right->n == node->n)
	{
		return (node->parent->left);
		/*Return left child if node is the right child*/
	}

	return (NULL); /* Return NULL if node has no parent-child relationship */
}
