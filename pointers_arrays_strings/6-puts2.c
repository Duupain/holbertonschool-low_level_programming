#include "main.h"
#include "2-strlen.c"
/**
*puts2 - print un nombre sur deux
*@str: string
*/
void puts2(char *str)
{
int start = 0;
for (start = 0; start < _strlen(str); start += 2)
{
_putchar(str[start]);
}
_putchar('\n');
}
