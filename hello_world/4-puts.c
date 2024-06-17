#include<stdio.h>
gcc -o 4-puts_0 -Wall -Werror -Wextra -pedantic -std=gnu89 4-puts.c 
int puts()
{
	//string initialisation
    char Mystr[] = "Programming is like building a multilingual puzzle";
    
    puts(Mystr); //writing the string to stdout
    
    return 0;
}
