#include "main.h"
/**
*_abs - returns the absolute value of an integer
* Return: x or resultat
*@x: number
*/
int _abs(int x)
{
int resultat;
if (x < 0)
{
resultat = (x * -1);
return (resultat);
}
else
{
return (x);
}
}
