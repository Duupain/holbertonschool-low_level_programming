#include "main.h"
/**
*_memcpy - copies memory area
*@n: nombre de byte
*@src: tableau 1
*@dest: prend le nombre de byte du tableau 1
*Return: dest
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i = 0;
for (i = 0; i < n; i++)
{
dest[i] = src[i];
}
return (dest);
}
