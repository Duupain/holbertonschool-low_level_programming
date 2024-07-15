#include <stdio.h>
#include "function_pointers.h"
/**
 * print_name - Imprime un nom en utilisant une fonction donnée.
 * @name: Le nom à imprimer.
 * @f: Un pointeur vers la fonction qui imprimera le nom.
 */

void print_name(char *name, void (*f)(char *))
{
	if (f != NULL && name != NULL)
	{
		f(name); /*Appelle la fonction pointée par 'f' avec 'name' comme argument*/
	}
}
