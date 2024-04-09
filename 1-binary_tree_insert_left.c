#include "binary_trees.h"

/**
 * binary_tree_insert_left - A function that inserts a node as the
 * left-child of another node
 * @parent: A Pointer to the parent node
 * @value: The value to be stored in the new node
 *
 * Return: A Pointer to the newly inserted left child, or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *leftnode;

	/* Check if the parent is NULL, insertion not allowed in this case */
	if (parent == NULL)
	{
		return (NULL);
	}

	/* Allocate memory for the new left node */
	leftnode = malloc(sizeof(binary_tree_t));
	if (leftnode == NULL)
	{
		return (NULL); /* Memory allocation failed */
	}

	/* Initialize the new left node */
	leftnode->parent = parent;
	leftnode->n = value;
	leftnode->left = parent->left;
	leftnode->right = NULL;

	/* Update pointers of existing nodes if parent already has a left child */
	if (parent->left != NULL)
	{
		leftnode->left = parent->left;
		parent->left->parent = leftnode;
	}

	/* Update the left child pointer of the parent */
	parent->left = leftnode;

	return (leftnode); /* Return pointer to the newly inserted left child */
}
