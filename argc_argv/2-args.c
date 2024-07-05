#include <stdio.h>
#include <stdlib.h>
/**
*main - program that prints all arguments it receives
*@argc: Nombre d'arguments de la ligne de commande
*@argv: Tableau de chaines contenant les arguments de la ligne de commande
*Return: 0
*/
int main(int argc, char **argv)
{
int i;
for (i = 0; i < argc; i++)
{
printf("%s\n", argv[i]);
}
return (0);
}
