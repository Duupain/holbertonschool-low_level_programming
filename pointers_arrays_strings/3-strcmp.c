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
int l = 0;
while (s1[i] != '\0')
{
i++;
}
while (s2[l] != '\0')
{
l++;
}
i = 0;
l = 0;
while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[l])
{
return (s1[i] - s2[l]);
}
if (s1[i] == s2[l])
{
return (0);
}
i++;
l++;
}
return (0);
}
