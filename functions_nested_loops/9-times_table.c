#include "main.h"

/**
*jack_bauer - prints every minute, starting from 00:00 to 23:59
*/
void times_table(void) {
int l, n, r;
for (l = 0; l < 10; l++) {
for (n = 0; n < 10; n++) {
r = n * l;
if (r > 9) {
_putchar((r / 10)+ '0');
}
_putchar((r % 10) + '0');
if (n != 9) {
_putchar(',');
_putchar(' ');		
}
}
_putchar('\n');
}
}
