#include <stdio.h>
/**
* main - Entry point
* Return: Always 0 (Success)
*/
int main(void)
{
int x;
for (x = 0; x < 10; x++)
{
putchar(48 + x);
if (x < 9)
{
}
}
putchar('\n');

return (0);
}
