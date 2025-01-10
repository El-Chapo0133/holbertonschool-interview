/*
 * ==========================================================================
 *
 *       Filename:  0-check_cycle.c
 *
 *    Description:  checks if there's a cycle in linked list
 *
 *        Version:  1.0
 *        Created:  10.01.2025 15:01:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  
 *
 * ==========================================================================
 */

#include "lists.h"

int check_cycle(listint_t *list)
{
	listint_t *temp = NULL;

	if (!list || !list->next)
		return (0);

	temp = lsit->next;
	while (temp && temp->next)
	{
		if (temp == list)
			return (1);
		list = list->next;
		temp = temp->next->next;
	}

	return (temp && temp == list);
}
