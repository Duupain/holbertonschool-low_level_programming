#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list.
 * @h: pointer to the list_t list to print
 *
 * Return: the number of nodes
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{

		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
			h = h->next;
		count++;
	}
	return (count);
}
