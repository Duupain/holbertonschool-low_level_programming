#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/*Fonction pour imprimer un caractère*/
void print_char(va_list args)
{
	printf("%c", (char)va_arg(args, int));
}

/*Fonction pour imprimer un entier*/
void print_integer(va_list args)
{
	printf("%d", va_arg(args, int));
}

/*print_float - Fonction pour imprimer un float*/
void print_float(va_list args)
{
	printf("%f", (float)va_arg(args, double));
}

/*Fonction pour imprimer une chaîne de caractères*/
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
 * Description: Cette fonction accepte un format spécifié sous forme de chaîne
 * de caractères où chaque caractère représente un type d'argument
 * à imprimer ('c' pour char, 'i' pour int, 'f' pour float,
 * 's' pour string). Elle utilise des fonctions spécifiques pour
 * imprimer chaque type et gère l'affichage de séparateurs entre
 * les valeurs imprimées.
 */
void print_all(const char *const format, ...)
{
	va_list args;
	/*Tableau de structures associant des caractères de format à des fonctions d'impression*/
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
