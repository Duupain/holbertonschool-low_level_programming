#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_list - frees a list_t list.
 * @head: Pointer to the pointer of the list_t (head of the list).
 *
 * Return: The address of the new node, or NULL if it failed.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		/*Step to store the next node*/
		temp = head->next;

		/*Step to free the string in the current node*/
		free(head->str);

		/*Step to free the current node*/
		free(head);

		/*Move to the next node*/
		head = temp;
	}
}
