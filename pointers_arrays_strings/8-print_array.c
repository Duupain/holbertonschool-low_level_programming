#include "main.h"
#include <stdio.h>
/**
*print_array - print element of the array
*@a: debut
*@n: fin
*/
void print_array(int *a, int n)
{
int i = 0;
for (i = 0; i < n; i++)
{
if (i == n - 1)
{
printf("%d", *(a + i));
}
else
{
printf("%d", *(a + i));
putchar(',');
putchar(' ');
}
}
putchar('\n');
}

