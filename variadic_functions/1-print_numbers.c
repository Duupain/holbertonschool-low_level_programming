#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - Imprime des nombres suivis d'une nouvelle ligne.
 * @separator: La chaîne à imprimer entre les nombres.
 * @n: Le nombre de paramètres passés à la fonction.
 *
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	int res = 0;
	unsigned int i;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		res = va_arg(args, int);
		printf("%d", res);

		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	printf("\n");
	va_end(args);
}
