#include "main.h"
/**
*_strlen_recursion - returns the length of a string
*@s: string
*Return: The length of the string
*/
int _strlen_recursion(char *s)
{
if (*s == '\0')
{
return (0);
}
/**si le car n'est pas 0 alors on compte ce car (1)*/
/**+ la longeur de la chaine restante calculee recursivement*/
return (1 + _strlen_recursion(s + 1));
}
