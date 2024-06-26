#include "main.h"
/**
*rev_string - reverse string
*@s: string
*/
void rev_string(char *s)
{
int start = 0, length = 0;
char temp;
while (s[start] != '\0')
{
start++;
length++;
}
length--;
for (start = 0; start < length / 2; start++)
{
temp = s[start];
s[start] = s[length - start];
s[length - start] = temp;
}
}
