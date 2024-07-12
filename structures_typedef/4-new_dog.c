#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: String to duplicate
 * Return: A pointer to the duplicated string or NULL if str is NULL
 *         or if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *str2;
	int size = 0, i;

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

/**
 * new_dog - Creates a new dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 * Return: A pointer to the new dog_t structure, or NULL if the function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *w;

	w = malloc(sizeof(dog_t));
	if (w == NULL)
	{
		return (NULL);
	}

	w->name = _strdup(name);
	if (w->name == NULL)
	{
		free(w);
		return (NULL);
	}

	w->owner = _strdup(owner);
	if (w->owner == NULL)
	{
		free(w->name);
		free(w);
		return (NULL);
	}

	w->age = age;

	return (w);
}
