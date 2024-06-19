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
putchar(number);  
if (number != 57)
{
putchar(',');
putchar(' ');
}
/*print the value of the variable*/
}
putchar('\n');

return (0);
}
