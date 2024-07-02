#include "main.h"
/**
*_memset - fills memory with a constant byte
*@s: point de depart dans la memoire
*@b: valeur a remplir
*@n: nombre d'octet a remplir
*Return: s
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i = 0;
for (i = 0; i < n; i++)
{
s[i] = b;
}
return (s);
}
