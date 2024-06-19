#include "main.h"
/**
* print_alphabet - Entry point
* Return: Always 0 (Success)
*/
void print_alphabet(void)
{
/*declare a variable*/
char alphabet;
for (alphabet = 'a'; alphabet <= 'z' ; alphabet++)
{
/*print the value of the variable*/
_putchar(alphabet);
}
_putchar('\n');
}

