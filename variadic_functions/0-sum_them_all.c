#include "variadic_functions.h"
#include <stdarg.h>
/**
 * sum_them_all - Retourne la somme de tous ses paramètres.
 * @n: Le nombre de paramètres passés à la fonction.
 * Return: La somme de tous les paramètres.
 */
int sum_them_all(const unsigned int n, ...)
{
	/*Déclaration de la liste de paramètres variadiques*/
	va_list args;
	/*Variable pour stocker la somme*/
	int sum = 0;
	unsigned int i;

	/*Initialisation de la liste de paramètres variadiques*/
	va_start(args, n);
	if (n == 0)
	{
		return (0);
	}
	/*Parcourir tous les paramètres variadiques*/
	for (i = 0; i < n; i++)
	{
		/*Ajouter chaque paramètre à la somme*/
		sum += va_arg(args, int);
	}
	/*Libère la mémoire de la liste variadique*/
	va_end(args);
	/*Retourner la somme des paramètres*/
	return (sum);
}
