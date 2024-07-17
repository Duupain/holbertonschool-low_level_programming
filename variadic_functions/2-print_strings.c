#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - Imprime des chaînes suivies d'une nouvelle ligne.
 * @separator: La chaîne à imprimer entre les chaînes.
 * @n: Le nombre de paramètres passés à la fonction.
 */

void print_strings(const char *separator, const unsigned int n, ...)
{

	unsigned int i;
	const char *str;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, const char *);
		if (str == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", str);
		}
		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	printf("\n");
	va_end(args);
}
