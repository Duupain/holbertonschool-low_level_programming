#include "main.h"
/**
* print_last_digit - print the last digit of a number
* Return: x or resultat
*@x: number
*/
int print_last_digit(int x)
{
int result;
if (x >= 0)
{
result = (x % 10);
_putchar(result + '0');
}
else if (x < 0)
{
result = ((x % 10) * -1);
_putchar(result + '0');
}
return (result);
}
