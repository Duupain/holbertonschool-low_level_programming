#include "main.h"
/**
*_strcat - concatenates two strings
*@dest: string 1
*@src: string 2
*Return: dest string 1
*/
char *_strcat(char *dest, char *src)
{
int i = 0;
int j = 0;
while (dest[j] != '\0')
{
j++;
}
for (i = 0; src[i] != '\0'; i++)
{
dest[i + j] = src[i];
}
dest[i + j] = '\0';
return (dest);
}
