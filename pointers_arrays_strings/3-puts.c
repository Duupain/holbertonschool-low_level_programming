#include "main.h"
/**
*_puts - prints a string, followed by a new line
*@str: string
*/
void _puts(char *str)
{
int e = 0;
while (str[e])
{
e++;
_putchar(str[e]);
}
_putchar('\n');
}
