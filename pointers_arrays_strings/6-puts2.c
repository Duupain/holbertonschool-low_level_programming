#include "main.h"
/**
*puts2 - print un nombre sur deux
*@str: string
*/
void puts2(char *str)
{
int start = 0;
while (str[start] != '\0')
{
_putchar(str[start]);
start += 2;
}
_putchar('\n');
}
