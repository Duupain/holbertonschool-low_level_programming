#include "main.h"
/**
*swap_int - swap the value of a and b
*@a: valeur a
*@b: valeur b
*/
void swap_int(int *a, int *b)
{
int change = *a;
*a = *b;
*b = change;
}
