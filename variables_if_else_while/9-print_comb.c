#include <stdio.h>
/**
* main - Entry point
* Return: Always 0 (Success)
*/
int main(void)
{
/*declare a variable*/
char number;
for (number = 48; number <= 57 ; number++)
{
if (number != 9)
{
/*print the value of the variable*/
putchar(number);
putchar(',');
putchar(' ');
}
}
putchar('\n');

return (0);
}
