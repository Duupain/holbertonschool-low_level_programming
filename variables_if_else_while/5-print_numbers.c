#include <stdio.h>
/* main - main block*/
/* Description: Print all possible combinations of single-digit numbers.*/
int main(void)
{
int x = 0;

while (x < 10)
{
printf("%d", x);
if (x < 9)
{
x++;
}
printf("\n");

return (0);
}
