#include "main.h"
/**
*_isupper -  checks for uppercase character
*@c: caractere
*return: 1 si uppercase , sinon 0
*/
int _isupper(int c)
{
if (c >= 65 && c <= 90)
{
return (1);
}
return (0);
}
