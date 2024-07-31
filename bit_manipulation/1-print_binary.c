#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	int bit;
	int leading = 0;

	/*Si le nombre est 0, imprimer 0*/
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	/*Parcourir chaque bit en commençant par le bit le plus significatif*/
	for (bit = sizeof(n) * 8 - 1; bit >= 0; bit--)
	{
		/*Décalage à droite et opération AND pour vérifier le bit actuel*/
		if ((n >> bit) & 1)
		{
			_putchar('1'); /*Imprimer 1 si le bit est 1*/

			/*quand 1 est trouvé, tous les zéros suivants sont significatifs*/
			leading = 1;
		}
		else if (leading)
		{
			_putchar('0'); /*Imprimer 0 seulement après avoir trouvé le premier 1*/
		}
	}
}
