#include "main.h"
/**
*_isalpha - look for a uppercase
* Return: 1 or 0
*@c: alphabet
*/
int _isalpha(int c)
{
if (c >= 97 && c <= 122)
{
return (1);
}
else if (c >= 65 && c <= 90)
{
return (1);
}
return (0);
}
