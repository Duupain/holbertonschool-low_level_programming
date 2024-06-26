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
int index = 0;
while (src[index])
{
dest[index] = src[index];
index++;
}
dest[index++] = '\0';
return (dest);
}
