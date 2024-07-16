#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Programme principal pour des opérations arithmétiques simples
 * @argc: Nombre d'arguments passés au programme.
 * @argv: Tableau de chaînes contenant les arguments.
 * Return: 0 en cas de succès, ou une autre valeur en cas d'erreur.
 */
int main(int argc, char *argv[])
{
	int a, b, result;
	int (*operation)(int, int);
	/*Vérifie si le nombre d'arguments est incorrect*/
	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	/*Convertit les arguments en entiers*/
	a = atoi(argv[1]); /*nombre 1*/
	b = atoi(argv[3]); /*nombre 2*/

	/* Obtient le pointeur vers la fonction pour l'opérateur donné */
	operation = get_op_func(argv[2]);

	/*verifie si l'operateur est valide*/
	if (operation == NULL)
	{
		printf("Error\n");
		return (99);
	}

	/*pour les division et modulo si le nombre 2(b) est egal a 0 return error */
	if ((*argv[2] == '/' || *argv[2] == '%') && b == 0)
	{
		printf("Error\n");
		return (100);
	}

	/*faire l'operation de a + b et print le resultat*/
	result = operation(a, b);
	printf("%d\n", result);

	return (0);
}
