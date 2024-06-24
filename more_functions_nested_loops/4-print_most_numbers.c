#include "main.h"
/**                                                                                                                                                                           *print_most_numbers - ecris les chiffre de 1 a 9 sauf 2 et 4
*/
void print_most_numbers(void)
{
int n;
for (n = '0'; n <= '9'; n++)
{
if (n != '2' && n != '4')
_putchar(n);
}
_putchar('\n');
}
