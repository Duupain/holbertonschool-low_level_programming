#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the number to modify.
 * @index: The index of the bit to set, starting from 0.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL)
	{
		return (-1);
	}
	/*Vérifiez si l'index est hors des limites de l'entier*/
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	/*Utilise OR bit à bit pour définir le bit à 1 à l'index donné*/
	*n |= (1UL << index); /*1UL = 1 unsigned long*/

	return (1);
}
