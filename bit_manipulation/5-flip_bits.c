#include "main.h"

/**
 * flip_bits - Retourne le nombre de bits à inverser
 * pour passer d'un nombre à un autre.
 * @n: Le premier nombre.
 * @m: Le second nombre.
 *
 * Return: Le nombre de bits nécessaires pour passer de n à m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	/* XOR n et m pour trouver les bits différents */
	unsigned long int xor_result = n ^ m;

	/* Compteur pour le nombre de bits différents */
	unsigned int count = 0;

	/* Compter le nombre de bits à 1 dans xor_result */
	while (xor_result)
	{
		/* Incrémenter le compteur si le dernier bit est 1 */
		count += xor_result & 1;

		/* Décaler les bits vers la droite de 1 position */
		xor_result >>= 1;
	}

	/* Retourner le nombre de bits différents */
	return (count);
}
