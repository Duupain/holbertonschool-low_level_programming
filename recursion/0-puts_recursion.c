#include "main.h"
/**
*_puts_recursion - Prints a string with recursion
*@s: string
*/
void _puts_recursion(char *s)
{
if (*s == '\0')
{
_putchar('\n');
return;
}
_putchar(*s);
/**appeler recursivement en passant ladresse du prochain caractere*/
_puts_recursion(s + 1);
}
