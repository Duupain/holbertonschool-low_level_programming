#include "main.h"
/**
*_strlen - renvoie le nb de caractere de la chaine s
*@s: nom du tableau (string)
*Return: nombre de boucle faite par e
*/
int _strlen(char *s)
{
int e = 0;
while (s[e])
{
e++;
}
return (e);
}
