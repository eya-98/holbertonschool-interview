#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * 
 * 
 */
listint_t *insert_node(listint_t **head, int number)
{
    
    listint_t *arg;
    if (!head)
	{
        return (NULL);
    }
    arg = malloc(sizeof(listint_t));
    if (arg == NULL)
    {
        return (NULL);
    }
    arg->n = number;
	arg->next = NULL;
    while((*head)->n < number)
    {
        head = &((*head)->next);
    }
    arg->next = (*head);
   (*head) = arg;
    return (arg);
}
