#include "main.h"
#include "2-strlen.c"
/**
*puts_half - print la moitier de la string
*@str: string
*/
void puts_half(char *str)
{
int start = 0, length = 0;
while (str[start] != 0)
{
start++;
length++;
}
start = length / 2;
while (start < length)
{
if (start % 2 == 1)
{
length = length + 1;
}
_putchar(str[start]);
start++;
}
_putchar('\n');
}
