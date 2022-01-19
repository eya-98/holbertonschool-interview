#include "search.h"
/**
 * linear_skip - Search for a value in a skip list.
 * @list: Pointer to the head of the skip list.
 * @value: Value to search for.
 * Return: Pointer to the first node where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *pointertoElement = list;
if (list == NULL)
return (NULL);
while (list->n < value && list->express)
{
pointertoElement = list;
list = list->express;
printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
}
if (value <= list->n)
printf("Value found between indexes [%ld] and [%ld]\n",
pointertoElement->index, list->index);
else
{
pointertoElement = pointertoElement->express;
while (list->next)
list = list->next;
printf("Value found between indexes [%ld] and [%ld]\n",
pointertoElement->index, list->index);
}
while (pointertoElement)
{
printf("Value checked at index [%ld] = [%d]\n",
pointertoElement->index, pointertoElement->n);
if (pointertoElement->n == value)
return (pointertoElement);
pointertoElement = pointertoElement->next;
}
return (NULL);
}
