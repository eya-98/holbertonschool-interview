#include "binary_trees.h"
/**
 * insertElement - Inserts an element in the tree
 * @head: The head
 * @value: new element to insert
 * Return: The new node
 **/
avl_t *insertElement(avl_t *head, int value)
{
	avl_t *NewElement = NULL;

	NewElement = malloc(sizeof(avl_t));
	if (NewElement == NULL)
		return (NULL);
	NewElement->n = value;
	NewElement->left = NULL;
	NewElement->right = NULL;
	NewElement->parent = head;

	return (NewElement);
}

/**
 * insert_start_end - Recursive fn Used to convert an array to AVL
 * @start: Head / from where to start
 * @array: array to convert to AVL
 * @first: Position where to start adding element
 * @last: Position where to stop adding element
 * Return: Head of the AVL
 **/
avl_t *insert_start_end(avl_t *start, int *array, int first, int last)
{
	int middle;
	avl_t *head;

	if (first > last)
		return (NULL);

	middle = (first + last) / 2;
	head = insertElement(start, array[middle]);

	if (head == NULL)
		return (NULL);

	head->left = insert_start_end(head, array, first, middle - 1);
	head->right = insert_start_end(head, array, middle + 1, last);

	return (head);
}

/**
 * sorted_array_to_avl - Converts an array to AVL
 * @array: Array to convert
 * @size: Number of elements in the array
 * Return: head of the AVL
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (insert_start_end(NULL, array, 0, size - 1));
}
