#include "binary_trees.h"
#include "17-binary_tree_sibling.c"

/**
 * binary_tree_uncle - A function that finds the uncle of a node
 * @node: A Pointer to the node to find the uncle
 *
 * Return: A Pointer to the uncle node, or NULL if no uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
