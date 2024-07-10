#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * array_range - Create an array of integer containing values from min to max
 * @min: The minimum value of the range (inclusive).
 * @max: The maximum value of the range (inclusive).
 * Return: Pointer to the created array or NULL if min > max or malloc fails
 */
int *array_range(int min, int max)
{
	unsigned int i, size;
	int *array;

	if (min > max)
	{
		return (NULL);
	}
	size = max - min + 1;
	array = malloc(size * sizeof(int));
	if (array == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		array[i] = min + i;
	}
	return (array);
}
