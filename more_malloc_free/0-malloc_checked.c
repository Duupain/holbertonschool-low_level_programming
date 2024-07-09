#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * malloc_checked - Alloue de la mémoire en utilisant malloc.
 * @b: Taille de la mémoire à allouer.
 * Return: Pointeur vers la mémoire allouée.
 * Termine le processus avec le statut 98 si l'allocation échoue.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	if (b <= 0)
	{
		exit(98);
	}
	ptr = malloc(b * sizeof(char));
	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}
