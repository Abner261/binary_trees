#include "binary_trees.h"

/**
 * binary_tree_depth - A function that measures the depth
 * of a node in a binary tree
 * @tree: A Pointer to the node to measure the depth
 *
 * Return: Depth of the node, 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (depth); /* Return 0 if tree is NULL */

	if (tree->parent == NULL)
		return (depth); /* Root node has depth 0 */

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
