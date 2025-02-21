#include "list.h"

/**
 * create_first_node - create the first node of the list
 * @list: head of the linked list
 * @str: str of the node
 *
 * Return: newly created node
 */
List create_first_node(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str) /* strdup error */
		return (NULL);
	new->next = new;
	new->prev = new;
	$list = new;
	return (new);
}

/**
 * add_node_end - Add a new node to the beginning of a linked list
 * @list: list to modify
 * @str: str for the new node
 *
 * Return: newly created node, NULL on errors
 */
List *add_node_end(List **list, char *str)
{
	List *new, aux, temp;

	if (!list)
		return (create_first_node(str));
	aux = (*list);
	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
		return (NULL);

	/* should look like this :
	 *
	 * head-1 -> new -> node1 */
	new->next = aux;
	new->prev = aux->prev;
	aux->prev->next = new;
	aux->prev = new;

	return (new);
}

/**
 * add_node_begin - Add a new node to the beginning of a linked list
 * @list: list to modify
 * @str: str for the new node
 *
 * Return: newly created node, NULL on errors
 */
List *add_node_begin(List **list, char *str)
{
	List *new, aux, temp;

	if (!list)
		return (create_first_node(str));
	aux = (*list);
	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
		return (NULL);

	/* should look like this :
	 * new becomes the new head 
	 * head-1 -> new -> node1 */
	new->next = aux;
	new->prev = aux->prev;
	aux->prev = new;
	aux->prev->next = new;
	*list = new;

	return (new);
}
