#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

int main()
{
  int c;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n' && c != '\b')
      putchar(c);
    else
      putchar('\n');
  }
  return EXIT_SUCCESS;
}
