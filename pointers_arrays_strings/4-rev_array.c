#include "main.h"
/**
*reverse_array - reverses the content of an array of integers
*@a: string
*@n: variable
*/
void reverse_array(int *a, int n)
{
int i, temp;
n--;
for (i = 0; i < (n + 1) / 2; i++)
{
temp = a[i];
a[i] = a[n - i];
a[n - i] = temp;
}
}
