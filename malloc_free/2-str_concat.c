#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - Concatène deux chaînes de caractères.
 * @s1: La première chaîne de caractères.
 * @s2: La deuxième chaîne de caractères.
 *
 * Return: Un pointeur vers un espace nouvellement alloué en mémoire
 *         contenant la chaîne concaténée,
 *         ou NULL si l'allocation échoue.
 */
char *str_concat(char *s1, char *s2)
{
	int i, j;
	int size1 = 0;
	int size2 = 0;
	char *res;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[size1] != '\0')
		size1++;

	while (s2[size2] != '\0')
		size2++;

	res = malloc((size1 + size2 + 1) * sizeof(char));
	if (res == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size1; i++)
	{
		res[i] = s1[i];
	}

	for (j = 0; j < size2; j++)
	{
		res[i + j] = s2[j];
	}
	res[i + j] = '\0';

	return (res);
}
