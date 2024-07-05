#include <stdio.h>
#include <stdlib.h>
/**
*main - program that adds positive numbers
*@argc: Nombre d'arguments de la ligne de commande
*@argv: Tableau de chaines contenant les arguments de la ligne de commande
*Return: 0
*/
int main(int argc, char **argv)
{
int i, j, result;
if (argc == 1)
{
printf("0\n");
return (0);
}
for (i = 1; i < argc; i++)
{
for (j = 0; argv[i][j] != '\0'; j++)
{
if (argv[i][j] < '0' || argv[i][j] > '9')
{
printf("Error\n");
return (1);
}
}
result += atoi(argv[i]);
}
printf("%d\n", result);
return (0);
}
