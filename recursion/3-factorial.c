#include "main.h"
/**
*factorial - returns the factorial of a given number
*@n: number
*Return: The factorial of n, or -1 if n is lower than 0 to indicate an error
*/
int factorial(int n)
{
if (n < 0)
{
return (-1);
}
if (n == 0)
{
return (1);
}
/**si n est posotif retourne n de maniere recursive jusqua 0*/
return (n * factorial(n - 1));
}
