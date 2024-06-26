#include "main.h"
#include <stdio.h>
/**
*_strcpy - prendre l'index de src pour la copier dans dest
*@dest:  pointeur de type chaine de character
*@src: pointeur de type chaine de character
*Return: dest
*/
char *_strcpy(char *dest, char *src)
{
int i = 0;
while (*src)
{
dest[i++] = *src;
src++;
}
dest[i++] = '\0';
return (dest);
}
