#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - Alloue de la mémoire pour un tableau et initialise à zéro.
 * @nmemb: Nombre d'éléments.
 * @size: Taille de chaque élément.
 * Return: Pointeur vers la mémoire allouée, ou NULL si échec.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *res;

	if (nmemb == 0)
	{
		return (NULL);
	}
	if (size == 0)
	{
		return (NULL);
	}
	res = malloc(nmemb * size);
	if (res == NULL)
	{
		return (NULL);
	}
	/*Initialiser la mémoire à zéro*/
	for (i = 0; i < (nmemb * size); i++)
	{
		res[i] = 0;
	}
	return (res);
}
