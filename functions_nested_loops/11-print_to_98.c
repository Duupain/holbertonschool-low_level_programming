#include "main.h"
/**
*print_to_98 - prints to 98
*@n: nombre
*/
void print_to_98(int n)
{
int res;
while (n != 98)
{
res = n;
if (res < 0)
{
_putchar('-');
res = -res;
}
if (res > 99)
{
_putchar((res / 100) + '0');
}
if (res > 9)
{
if (res > 99)
{
_putchar(((res / 10) % 10) + '0');
}
else
{
_putchar((res / 10) + '0');
}
}
_putchar((res % 10) + '0');
_putchar(',');
_putchar(' ');
if (res > 98)
{
n--;
}
else
{
n++;
}
}
_putchar('9');
_putchar('8');
_putchar('\n');
}
