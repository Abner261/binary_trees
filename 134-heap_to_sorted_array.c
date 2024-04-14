#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 * Return: Pointer to the sorted array or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array;
    size_t i = 0, heap_size;

    if (!heap)
        return (NULL);

    heap_size = binary_tree_size(heap);
    sorted_array = malloc(sizeof(int) * heap_size);
    if (!sorted_array)
        return (NULL);

    while (heap)
    {
        sorted_array[i++] = heap->n;
        heap_extract(&heap);
    }

    *size = heap_size;
    return (sorted_array);
}

