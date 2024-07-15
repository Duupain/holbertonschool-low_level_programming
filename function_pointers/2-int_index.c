#include "function_pointers.h"
#include <stdio.h>
#include <stddef.h>

/**
 * int_index - Cherche un entier dans un tableau
 * selon une fonction de comparaison.
 * @array: Le tableau d'entiers.
 * @size: Le nombre d'éléments dans le tableau.
 * @cmp: Un pointeur vers la fonction de comparaison.
 * Return: L'index du premier élément pour lequel
 * la fonction cmp ne retourne pas 0,
 * ou -1 si aucun élément ne correspond ou si la taille est <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
	{
		return (-1);
	}
	if (size <= 0)
	{
		return (-1);
	}
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
	}
	return (-1);
}
