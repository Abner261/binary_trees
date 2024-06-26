#include "binary_trees.h"

/**
 * binary_tree_rotate_left - A function that performs a
 * left-rotation on a binary tree
 * @tree: A pointer to the root node of the tree to rotate
 *
 * Return: A pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (!tree || !tree->right)
		return (NULL);
	new_root = tree->right;
	temp = new_root->left;
	new_root->left = tree;
	tree->right = temp;
	if (temp)
		temp->parent = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;
	if (new_root->parent)
	{
		if (new_root->parent->left == tree)
			new_root->parent->left = new_root;
		else
			new_root->parent->right = new_root;
	}
	return (new_root);
}
