#include "main.h"
/**
* print_alphabet_x10 - check the code
* Return: Always 0.
*/
void print_alphabet_x10(void)
{
char alphabet;
char i;
for (i = 0 ; i < 10 ; i = i + 1)
{
for (alphabet = 'a'; alphabet <= 'z' ; alphabet++)
{
/*print the value of the variable*/
_putchar(alphabet);
}
_putchar('\n');
}
}
