#include "main.h"
/**
*_pow_recursion - Fonction recursive pour calculer la puissance x^y
*@x: base de la puissance
*@y: exposant de la puissance
*Return: resultat de x eleve a la puissance y
*/
int _pow_recursion(int x, int y)
{
if (y < 0)
{
return (-1);
}
if (y <= 0)
{
return (1);
}
/**multiplies x par lui meme y-1 fois et ensuite multiplie le resultat par x*/
return (_pow_recursion(x, y - 1) * x);
}
