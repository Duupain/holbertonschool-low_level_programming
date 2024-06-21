#include "main.h"
/**
*times_table - prints 9table
*/
void times_table(void)
{
int l, n, r;
for (l = 0; l < 10; l++) {
_putchar('0');

for (n = 1; n < 10; n++) {
_putchar(',');
_putchar(' ');

r = n * l;
if (r <= 9) {
_putchar(' ');
} else {
_putchar((r / 10)+ '0');
}

_putchar((r % 10) + '0');
}
_putchar('\n');
}
