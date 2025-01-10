/*
 * ==========================================================================
 *
 *       Filename:  0-is_palindrome.c
 *
 *    Description:  check if a given linked list is palindrome
 *
 *        Version:  1.0
 *        Created:  10.01.2025 13:35:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  
 *
 * ==========================================================================
 */
#include <stdio.h>
#include "lists.h"



listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;
	listint_t *current = head;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

int is_palindrome(listint_t **head)
{
	listint_t *temp = *head;
	listint_t *second_half = *head;

	if (!(*head) || !(*head)->next)
		return (0);

	while (temp && temp->next)
	{
		second_half = second_half->next;
		temp = temp->next->next;
	}
	second_half = reverse_list(second_half);

	while (second_half)
	{
		if ((*head)->n != second_half->n)
			return (0);
		second_half = second_half->next;
		(*head) = (*head)->next;
	}
	return (1);
}
