#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = binary_tree_node(NULL, value);
    heap_t *parent;

    if (new_node == NULL)
        return NULL;

    if (*root == NULL)
    {
        *root = new_node;
        return new_node;
    }

    /* Insert new node at the next available position */
    parent = find_parent(*root);
    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;
    new_node->parent = parent;

    /* Percolate the new node up the tree */
    heapify_up(new_node);

    return new_node;
}

/**
 * find_parent - Finds the parent for the next available position in the heap
 * @root: Pointer to the root node of the Heap
 *
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *root)
{
    heap_t *parent;
    queue_t *queue = NULL;

    enqueue(&queue, root);

    while (queue)
    {
        parent = dequeue(&queue);
        if (parent->left == NULL || parent->right == NULL)
            break;

        enqueue(&queue, parent->left);
        enqueue(&queue, parent->right);
    }

    return parent;
}

/**
 * heapify_up - Percolates a node up the heap until it satisfies the Max Heap property
 * @node: Pointer to the node to be percolated up
 */
void heapify_up(heap_t *node)
{
    while (node->parent != NULL && node->n > node->parent->n)
    {
        swap_values(node, node->parent);
        node = node->parent;
    }
}

/**
 * swap_values - Swaps the values of two nodes
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_values(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * enqueue - Enqueues a node into a queue
 * @queue: Pointer to the pointer to the queue
 * @node: Pointer to the node to enqueue
 */
void enqueue(queue_t **queue, heap_t *node)
{
    queue_t *new_node = malloc(sizeof(queue_t));
    queue_t *temp = *queue;

    if (new_node == NULL)
        return;

    new_node->node = node;
    new_node->next = NULL;

    if (*queue == NULL)
    {
        *queue = new_node;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
}

/**
 * dequeue - Dequeues a node from a queue
 * @queue: Pointer to the pointer to the queue
 *
 * Return: Pointer to the dequeued node
 */
heap_t *dequeue(queue_t **queue)
{
    queue_t *temp = *queue;
    heap_t *node;

    if (*queue == NULL)
        return NULL;

    *queue = (*queue)->next;
    node = temp->node;
    free(temp);

    return node;
}

