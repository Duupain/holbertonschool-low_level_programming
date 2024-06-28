#include "main.h"
/**
*_strncat - concatenates n de src dans dest
*@dest: string 1
*@src: string 2
*@n: valeur de byte array
*Return: dest
*/
char *_strncat(char *dest, char *src, int n)
{
int i = 0;
int j = 0;
if (n <= 0)
{
return (dest);
}
while (dest[j] != '\0')
{
j++;
}
for (i = 0; i < n; i++)
{
dest[i + j] = src[i];
}
dest[i + j] = '\0';
{
return (dest);
}
}
