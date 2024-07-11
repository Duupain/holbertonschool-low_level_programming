#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

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
	w->name = _strdup(name);
	w->owner = _strdup(owner);
	if (w->name == NULL)
	{
		return (NULL);
	}
	if (w->owner == NULL)
	{
		return (NULL);
	}
	return (w);
}
/**
 *_strdup - returns a pointer to a newly allocated space in memory,
 *which contains a copy of the string given as a parameter.
 *@str: string to duplicate
 *Return: a pointer to the duplicated string or NULL if str is NULL
 *or if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *str2;
	int size = 0;
	int i;
	if (str == NULL)
	{
		return (NULL);
	}
	while (str[size] != '\0')
	{
		size++;
	}
	size++;
	str2 = malloc(size * sizeof(char));
	if (str2 == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		str2[i] = str[i];
	}
	return (str2);
}
