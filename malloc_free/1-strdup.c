#include "main.h"
#include <stdio.h>
#include <stdlib.h>

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
