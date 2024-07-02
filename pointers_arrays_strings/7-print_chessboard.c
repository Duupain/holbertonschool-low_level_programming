#include "main.h"
/**
*print_chessboard - parcourir chaques ligne et colone
*@a: tableau
*/
void print_chessboard(char (*a)[8])
{
int ligne;
int colone;
while (ligne < 8)
{
colone = 0;
while (colone < 8)
_putchar (a[ligne][colone++]);
_putchar ('\n');
ligne++;
}
}

