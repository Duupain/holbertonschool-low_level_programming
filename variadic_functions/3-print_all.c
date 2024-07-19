#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

void print_char(va_list args)
{
	printf("%c", (char)va_arg(args, int));
}

void print_integer(va_list args)
{
	printf("%d", va_arg(args, int));
}

void print_float(va_list args)
{
	printf("%f", (float)va_arg(args, double));
}

void print_string(va_list args)
{
	char *str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(nil)";
	}
	printf("%s", str);
}

/**
 * print_all - Imprime tout en fonction du format spécifié.
 * @format: Liste des types d'arguments passés à la fonction.
 */
void print_all(const char *const format, ...)
{
	va_list args;
	tableau vlr[] = {
			{"c", print_char},
			{"i", print_integer},
			{"f", print_float},
			{"s", print_string},
			{NULL, NULL}};

	int i = 0, j = 0;
	char *separator = "";

	va_start(args, format);

	while (format && format[j])
	{
		i = 0;
		while (vlr[i].c != NULL)
		{
			if (*(vlr[i].c) == format[j])
			{
				printf("%s", separator);
				vlr[i].f(args);
				separator = ", ";
				break;
			}
			i++;
		}
		j++;
	}

	printf("\n");
	va_end(args);
}
