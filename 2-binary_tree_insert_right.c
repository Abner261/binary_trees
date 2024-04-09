#include "binary_trees.h"

/**
 * binary_tree_insert_right - A function that inserts a node as the
 * right-child of another node
 * @parent: A Pointer to the parent node
 * @value: The value to be stored in the new node
 *
 * Return: A Pointer to the newly inserted right child or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *rightnode;

	/* Check if the parent is NULL, insertion not allowed in this case */
	if (parent == NULL)
	{
		return (NULL);
	}

	/* Allocate memory for the new right node */
	rightnode = malloc(sizeof(binary_tree_t));
	if (rightnode == NULL)
	{
		return (NULL); /* Memory allocation failed */
	}

	/* Initialize the new right node */
	rightnode->parent = parent;
	rightnode->n = value;
	rightnode->right = parent->right;
	rightnode->left = NULL;

	/* Update pointers of existing nodes if parent already has a right child */
	if (rightnode->right != NULL)
	{
		rightnode->right = parent->right;
		parent->right->parent = rightnode;
	}

	/* Update the right child pointer of the parent */
	parent->right = rightnode;

	return (rightnode); /* Return pointer to the newly inserted right child */
}
