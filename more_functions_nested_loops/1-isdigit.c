#include "main.h"
/**
*_isdigit - est un chiffre entre 1 et 9
*@c:caractere
*Return: 1 if  digit, if not 0
*/
int _isdigit(int c)
{
if (c >= 48 && c <= 57)
{
return (1);
}
return (0);
}
