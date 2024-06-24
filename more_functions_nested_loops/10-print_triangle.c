#include "main.h"
/**
*print_triangle - dessine un triangle
*@size: taille
*Return: 0
*/
void print_triangle(int size)
{
int a, b;
if (size <= 0)
{
_putchar('\n');
return;
}
for (a = 0;  a < size; a++)
{
for (b = 0; b < size; b++)
{
if ((a + b) < (size - 1))
{
_putchar(' ');
}
else
{
_putchar('#');
}
}
_putchar('\n');
}
}
