#include <stdio.h>
/**
* main - Entry point
* Return: Always 0 (Success)
*/
int main(void)
{
char number;
char hexadecimal;

for (number = 48; number <= 57; number++)
{
/*print the value of the variable*/
putchar(number);
}
/*declare a variable*/
for (hexadecimal = 97; hexadecimal <= 102; hexadecimal++)
{

/*print the value of the variable*/
putchar(hexadecimal);
}
putchar('\n');

return (0);
}
