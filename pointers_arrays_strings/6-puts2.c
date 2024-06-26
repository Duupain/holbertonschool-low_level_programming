#include "main.h"
/**
*puts2 - print un nombre sur deux
*@str: string
*/
void puts2(char *str)
{
int start = 0;
for (start = 0; str[start] != '\0'; start += 2)
{
_putchar(str[start]);
}
_putchar('\n');
}
