#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - print un caractere
 * @args: Liste les arguments
 */
void print_char(va_list args)
{
	printf("%c", (char)va_arg(args, int));
}

/**
 * print_integer - print un entier
 * @args: Liste les arguments
 */
void print_integer(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - print un float
 * @args: Liste les arguments
 */
void print_float(va_list args)
{
	printf("%f", (float)va_arg(args, double));
}

/**
 * print_string - print une chaine de caractere
 * @args: Liste les arguments
 */
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
 *
 * Description: Cette fonction accepte
 * un format spécifié sous forme de chaîne
 * de caractères où chaque caractère représente un type d'argument
 * à imprimer ('c' pour char, 'i' pour int, 'f' pour float,
 * 's' pour string). Elle utilise des fonctions spécifiques pour
 * imprimer chaque type et gère l'affichage de séparateurs entre
 * les valeurs imprimées.
 */
void print_all(const char *const format, ...)
{
	va_list args;
	/*Tableau associant des caractères de format à des fonctions d'impression*/
	tableau vlr[] = {
			{"c", print_char},
			{"i", print_integer},
			{"f", print_float},
			{"s", print_string},
			{NULL, NULL}};

	int i = 0, j = 0;
	char *separator = "";

	va_start(args, format);

	/*Parcourir chaque caractère du format*/
	while (format && format[j])
	{
		i = 0;
		/*Parcourir le tableau de fonctions pour trouver une correspondance*/
		while (vlr[i].c != NULL)
		{
			/*Si le caractère du format correspond à un type connu*/
			if (*(vlr[i].c) == format[j])
			{
				printf("%s", separator); /*Imprimer le séparateur*/
				vlr[i].f(args);					 /*Appeler la fonction d'impression correspondante*/
				separator = ", ";				 /*Mettre à jour le séparateur*/
				break;									 /*Sortir de la boucle interne*/
			}
			i++;
		}
		j++;
	}

	printf("\n");
	va_end(args);
}
