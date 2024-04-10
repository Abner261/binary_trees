#include "binary_trees.h"

/**
 * binary_tree_is_full - A function that checks if a binary tree is full
 * @tree: A Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 if tree is NULL or not full
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full_right, is_full_left;

	if (tree == NULL)
		return (0); /* Return 0 if tree is NULL */

	if (tree->left == NULL && tree->right == NULL)
		return (1); /* If the node is a leaf, it's full by definition */

	if (tree->left == NULL && tree->right != NULL)
		return (0); /* If the node has one child, it's not full */

	if (tree->left != NULL && tree->right == NULL)
		return (0);

	is_full_left = binary_tree_is_full(tree->left);
	is_full_right = binary_tree_is_full(tree->right);

	if (is_full_right == 1 && is_full_left == 1)
		return (1);

	return (0);
}
