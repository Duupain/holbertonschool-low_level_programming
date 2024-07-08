#include <stdlib.h>
#include "main.h"
#include <stdio.h>
/**
*create_array - creates an array of chars, initializes it with a specific char
*@size: taille du tableau
*@c: Caractere avec lequel initialiser le tableau
*Return: Pointeur vers le tableau de caracteres ou NULL si l'allocation echoue
*/
char *create_array(unsigned int size, char c)
{
char *array;
unsigned int i;
if (size == 0)
{
return (NULL);
}
array = malloc(size * sizeof(char));
if (array == 0)
{
return (NULL);
}
for (i = 0; i < size; i++)
{
array[i] = c;
}
return (array);
}
