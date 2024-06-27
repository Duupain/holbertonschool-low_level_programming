#include "main.h"
/**
*
*
*/
char *_strncat(char *dest, char *src, int n)
{
  int i = 0;
  int j = 0;
  if (n <= 0)
    {
      return (dest);
    }
  while ( n
  while (dest[j] != '\0')
    {
     j++;
   }
      for (i = 0; src[i] != '\0'; i++)
       {
	 dest[i + j] = src[i];
       }
      dest[i + j] = '\0';
	    {
	  return (dest);
	}
	}
