#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

void print_char(va_list i)
{
	printf("%c", va_arg(i, char));
}

void print_integer(va_list i)
{
	printf("%d", va_arg(i, int));
}
void print_float(va_list i)
{
	printf("%f", va_arg(i, float));
}
void print_string(va_list i)
{
	printf("%s", va_arg(i, char *));
}

/**
 *
 *
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
	while (format != '\0')
	{
		if (*(format) == vlr)
		{
			return (vlr.f);
		}
		format++;
	}
	return (NULL);
}