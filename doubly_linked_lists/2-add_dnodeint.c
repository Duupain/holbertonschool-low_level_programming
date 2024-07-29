#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 * @head: Pointer to the pointer of the head of the list.
 * @n: Integer value to store in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	/*allocation de memoire pour le nouveau noeud*/
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	/* Update the previous head's prev pointer if the list is not empty */
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	/* Update the head pointer to the new node */
	*head = new_node;

	return (new_node);
}
