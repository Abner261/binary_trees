#include "binary_trees.h"

/**
 * binary_tree_nodes - A function that counts the nodes with at least 1
 * child in a binary tree
 * @tree: A Pointer to the root node of the tree to count the nodes
 *
 * Return: Number of nodes with at least 1 child in the tree
 * 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* Base case: if tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/**
     * If the current node has at least 1 child
     * return 1 plus the count in left and right subtrees
     **/
	if (tree->left != NULL || tree->right != NULL)
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

	/* If the current node is a leaf, return 0 */
	return (0);
}
