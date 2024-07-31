#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to check.
 * @index: The index of the bit to get, starting from 0.
 *
 * Return: The value of the bit at index `index`, or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	/*Vérifie si l'index est hors des limites du type unsigned long int.*/
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	/*Décale a droite de 'index' bits et effectue un AND avec 1.*/
	/*Ca isole le bit à la position 'index'.*/
	if ((n >> index) & 1)
	{
		/*Si le bit est 1, retourne 1*/
		return (1);
	}
	else
	{
		/*Si le bit est 0, retourne 0.*/
		return (0);
	}
}
