#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: Pointer to the pointer of the head of the list.
 * @n: Integer value to store in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	/*allocation de memoire pour le nouveau noeud*/
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;

	else
	{
		/* Traverse to the end of the list */
		dlistint_t *current = *head;

		while (current->next != NULL)
			current = current->next;

		/* Append the new node at the end */
		current->next = new_node;
		new_node->prev = current;
	}
	return (new_node);
}
