#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string
 * @s2: The second string
 *
 * Return: A pointer to a newly allocated space in memory
 *         containing the concatenated string,
 *         or NULL if allocation fails.
 */
char *str_concat(char *s1, char *s2)
{
  int i, j;
  int size1 = 0;
  int size2 = 0;
  char *res;
  if (s1 == NULL)
  {
    s1 = "";
  }
  if (s2 == NULL)
  {
    s2 = "";
  }
  while (s1[size1] != '\0')
    size1++;

  while (s2[size2] != '\0')
    size2++;
  res = malloc((size1 + size2 + 1) * sizeof(char));
  if (res == NULL)
  {
    return (NULL);
  }
  for (i = 0; i < size1; i++)
  {
    res[i] = s1[i];
  }
  for (j = 0; j < size2; j++)
  {
    res[i + j] = s2[j];
  }
  res[i + j] = '\0';
  return (res);
}