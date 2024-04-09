#include "binary_trees.h"

/**
 * binary_tree_preorder - A function that goes through a binary tree
 * using pre-order traversal
 * @tree: A Pointer to the root node of the tree to traverse
 * @func: A Pointer to a function to call for each node
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check if tree or func is NULL, do nothing in such cases */
	if (tree == NULL || func == NULL)
	{
		return;/* do nothing*/
	}

	/* Call the function on the data of the current node */
	func(tree->n);

	/* Recursively traverse the left subtree in pre-order */
	binary_tree_preorder(tree->left, func);

	/* Recursively traverse the right subtree in pre-order */
	binary_tree_preorder(tree->right, func);
}
