#include <stdio.h>
#include <stdlib.h>

int main()
{
  int c, amount;
  amount = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n')
      ++amount;
  }
  printf("\n%d\n", amount);
  return EXIT_SUCCESS;
}
