#ifndef GUARD
#define GUARD

#include <stdarg.h>

/**
 * struct spec - la structure pour print un arguments
 * @c: Type d'arguments
 * @f: la fonction pour print un arguments
 */
typedef struct spec
{
  char *c;
  void (*f)(va_list args);
} tableau;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char *const format, ...);

#endif
