#include "binary_trees.h"
/**
 * bst_search - A function that searches for a value in a Binary Search Tree
 * @tree: The root of the tree to evaluate
 * @value: The node to find
 * Return: 1 if exits 0 if no
 */

bst_t *bst_search(const bst_t *tree, int value)
{

	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
	return (NULL);
}
