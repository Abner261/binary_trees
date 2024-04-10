#include "binary_trees.h"

/**
 * binary_tree_size - A function that measures the size of a binary tree
 * @tree: A Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	/* Base case: if tree is NULL, return 0 */
	if (tree == NULL)
	{
		return (0);
	}

	/**
	 * Recursive case: calculate the size of left and right subtrees
	 * add 1 for the current node
	 **/

	size = binary_tree_size(tree->left) + 1;
	size += binary_tree_size(tree->right);

	return (size);
}
