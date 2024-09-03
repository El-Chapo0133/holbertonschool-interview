#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (head == NULL)
	{
		head = &new;
		return (new);
	}

	while ((*head)->next != NULL && (*head)->next->n < number)
		head = &(*head)->next;

	new->next = (*head)->next;
	(*head)->next = new;

	return (new);
}
