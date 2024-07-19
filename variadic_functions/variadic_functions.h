#ifndef GUARD
#define GUARD

#include <stdarg.h>

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
