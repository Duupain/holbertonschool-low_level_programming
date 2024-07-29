#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Pointer to the pointer of the list_t (head of the list).
 * @str: String to add to the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */

list_t *add_node(list_t **head, const char *str)
{
	/*allocation de memoire pour le nouveau noeud*/
	list_t *new_node = malloc(sizeof(list_t));
	unsigned int len = 0;

	if (new_node == NULL)
	{
		return (NULL);
	}

	/*dupliquer la chaine de caractere et gere l'erreur si elle echoue*/
	new_node->str = strdup(str);

	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	while (str[len] != '\0')
		len++;

	new_node->len = strlen(str); /*Calculer la longueur de la chaîne*/

	new_node->next = *head; /*Faire pointer le nouveau nœud vers le head*/

	*head = new_node;

	return (new_node);
}
