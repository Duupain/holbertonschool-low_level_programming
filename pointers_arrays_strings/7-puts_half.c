#include "main.h"
#include "2-strlen.c"
/**
*puts_half - print la moitier de la string
*@str: string
*/
void puts_half(char *str)
{
  int start = 0, length = 0;
  while (str[length] != 0)
    {
      length++;
      }
  if (length % 2 == 0)
    {
      start = length / 2;
    }
  else
    {
      start = (length + 1) / 2;
    }
  while (start < length)
    {
      _putchar(str[start]);
      start++;
    }
  _putchar('\n');
}
