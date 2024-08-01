#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number to modify.
 * @index: Index of the bit to set to 0, starting from 0.
 *
 * Return: 1 if successful, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (n == NULL)
	{
		return (-1);
	}
	/*Vérifiez si l'index est hors des limites de l'entier*/
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	/*Crée un masque avec un 1 à la position de l'index*/
	mask = 1UL << index;

	/*Inverse les bits du masque pour mettre 0 à la position de l'index*/
	mask = ~mask;

	/*Applique le masque pour mettre le bit à 0*/
	*n &= mask;

	return (1); /*Retourne 1 pour indiquer le succès*/
}
