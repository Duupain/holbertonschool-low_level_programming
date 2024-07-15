#include "function_pointers.h"
#include <stdio.h>
#include <stddef.h>

/**
 * array_iterator - Exécute une fonction sur chaque élément dun tableau
 * @array: Le tableau d'entiers.
 * @size: La taille du tableau.
 * @action: pointeur vers fonction à exécute sur chaque élément du tableau
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
