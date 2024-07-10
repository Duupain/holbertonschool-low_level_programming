#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - Concatène deux chaînes de caractères.
 * @s1: Première chaîne.
 * @s2: Deuxième chaîne.
 * @n: Nombre de caractères à copier de s2.
 * Return: Pointeur vers la nouvelle chaîne concatene ou NULL si échec
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j;
	unsigned int size1 = 0, size2 = 0;
	char *res;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	while (s1[size1] != '\0')
	{
		size1++;
	}
	while (s2[size2] != '\0')
	{
		size2++;
	}
	if (n >= size2)
	{
		n = size2;
	}
	res = malloc(size1 + n + 1);
	if (res == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size1; i++)
	{
		res[i] = s1[i];
	}
	for (j = 0; j < n; j++)
	{
		res[i + j] = s2[j];
	}
	res[i + j] = '\0';

	return (res);
}
