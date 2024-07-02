#include "main.h"
#include <stddef.h>
/**
*_strchr -  locates a character in a string
*@s: string
*@c: caractere que l'on cherche
*Return: si les car correspondent return un pointeur vers ce car dans s
*/
char *_strchr(char *s, char c)
{
unsigned int i = 0;
while (s[i])
{
if (s[i] == c)
{
return (&s[i]);
}
i++;
}
return (NULL);
}
