#include "main.h"
/**
* _atoi - Convert a string to an integer.
* @s: The string to be converted.
*Return: The integer value of the string.
*/
int _atoi(char *s)
{
long int result = 0;
long int sign = 1;
long int i = 0;
while (s[i] != '\0')
{
if (s[i] == '-')
{
sign *= -1;
}
else if (s[i] == '+')
{
sign *= 1;
}
else if (s[i] >= '0' && s[i] <= '9')
{
break;
}
i++;
}
while (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
i++;
}
return (result *sign);
}
