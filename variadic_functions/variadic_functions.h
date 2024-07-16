#ifndef GUARD
#define GUARD

typedef struct Format
{
  char *type;
  void (*print_format)(va_list);
} Format_t;

int sum_them_all(const unsigned int n, ...);

#endif