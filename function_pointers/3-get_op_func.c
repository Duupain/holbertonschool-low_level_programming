#include "3-calc.h"
#include <stddef.h>

/**
 * get_op_func - Selects the correct function to perform
 * the operation asked by the user.
 * @s: The operator passed as argument.
 *
 * Return: Pointer to the function
 * that corresponds to the operator
 * If s does not match any of the 5 expected operators,
 * return NULL.
 */

int (*get_op_func(char *s))(int, int)
{
  op_t ops[] = {
      {"+", op_add},
      {"-", op_sub},
      {"*", op_mul},
      {"/", op_div},
      {"%", op_mod},
      {NULL, NULL}};
  int i = 0;

  while (s != ops)
  {
    /**Boucle pour parcourir le tableau ops
     * jusqu'à trouver une correspondance ou atteindre la fin
     * Vérifie également que l'opérateur est un seul caractère
     */
    if (*(ops[i].op) == *s && s[1] == '\0')
    {
      /*Retourne le pointeur vers la fonction associée à l'opérateur*/
      return (ops[i].f);
    }
    i++;
  }
  return (NULL);
}