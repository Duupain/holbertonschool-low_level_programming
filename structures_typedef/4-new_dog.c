#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
#include <string.h>

/**
 *new_dog - Crée un nouveau chien.
 *@name: Le nom du chien.
 *@age: L'âge du chien.
 *@owner: Le propriétaire du chien.
 *Return: Un pointeur vers la nouvelle structure dog_t,ou NULL en cas d'échec.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *w;
	w = malloc(sizeof(dog_t));
	if (w == NULL)
	{
		return (NULL);
	}
	w->age = age;
	w->name = name;
	w->owner = owner;
	return (w);
}
