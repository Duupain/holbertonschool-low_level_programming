#include "main.h"
/**
*more_numbers - ecris 0 a 14 sur 10 lignes
*@n: nombre
*@l: lignes
*/
void more_numbers(void)
{
int n, l;
for (l = 0; l <= 14; l++)
{
for (n = 0; n < 15 ; n++)
{
if (n > 9)
{
_putchar((n / 10) + '0');
}
_putchar((n % 10) + '0');
}
_putchar('\n');
}
}
