#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  printf("%d\n", SCHAR_MIN);
  printf("%d\n", SCHAR_MAX);
  printf("%d\n", SHRT_MIN);
  printf("%d\n", SHRT_MAX);
  printf("%d\n", INT_MIN);
  printf("%d\n", INT_MAX);
  printf("%ld\n", LONG_MIN);
  printf("%ld\n", LONG_MAX);
  printf("%u\n", UCHAR_MAX);
  printf("%u\n", USHRT_MAX);
  printf("%u\n", UINT_MAX);
  printf("%lu\n", ULONG_MAX);
  return EXIT_SUCCESS;
}
