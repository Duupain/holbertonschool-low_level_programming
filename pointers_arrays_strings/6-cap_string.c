#include "main.h"
/**
*
*
*
*/
char *cap_string(char *str)
  {
    int i = 0;
 for (i = 1; str[i] != '\0'; i++)
   {
        if (str[i] >= 'a' && str[i] <= 'z')
	  {
            if (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n' ||
                str[i - 1] == ',' || str[i - 1] == ';' || str[i - 1] == '.' ||
                str[i - 1] == '!' || str[i - 1] == '?' || str[i - 1] == '"' ||
                str[i - 1] == '(' || str[i - 1] == ')' || str[i - 1] == '{' || str[i - 1] == '}')
	      {
                str[i] -= 32;
            }
        }
    }

 return (str);
}
