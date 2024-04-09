#include "binary_trees.h"

/**
 * binary_tree_postorder - A function that goes through a binary tree
 * using post-order traversal
 * @tree: A Pointer to the root node of the tree to traverse
 * @func: A Pointer to a function to call for each node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check if tree or func is NULL, do nothing in such cases */
	if (tree == NULL || func == NULL)
		return;

	/* Recursively traverse the left subtree in post-order */
	binary_tree_postorder(tree->left, func);

	/* Recursively traverse the right subtree in post-order */
	binary_tree_postorder(tree->right, func);

	/* Call the function on the data of the current node */
	func(tree->n);
}
