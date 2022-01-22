#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *p1, *p2;

	if (head == NULL)
		return (0);
	node1 = head;
	node2 = head;
	while (p1 && p2 && p2->next)
	{
		node1 = p1->next;
		node2 = p2->next->next;
		if (node1 == node2)
			break;
	}
	if (node1 != node2)
		return (NULL);
	node1 = head;

	while (node1 != node2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return (node2);
}