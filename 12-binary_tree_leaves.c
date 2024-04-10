#include "binary_trees.h"

/**
 * binary_tree_leaves - A function that counts the leaves in a binary tree
 * @tree: A Pointer to the root node of the tree to count the leaves
 *
 * Return: Number of leaves in the tree, 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* Base case: if tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* If the current node is a leaf, return 1 */
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}

	/* Recursive case: count the leaves in left and right subtrees */
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
