#include "main.h"
/**
*_strcmp - compares two strings.
*@s1: string 1
*@s2: string 2
*Return: 0 si elle sont egale,
*/
int _strcmp(char *s1, char *s2)
{
int i = 0;
while (i < s1[i])
{
if (s1[i] != s2[i])
{
return (s1[i] - s2[i]);
}
if (s1[i] == s2[i])
{
return (0);
}
i++;
}
return (0);
}
