#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

int main()
{
  int c;
  int flag;

  flag = NO;

  while ((c = getchar()) != EOF) {
    if (c != ' ' && flag == YES) {
      flag = NO;
      putchar(c);
    } else if (c == ' ' && flag == NO) {
      flag = YES;
      putchar(c);
    } else if (c == ' ' && flag == YES)
      ;
    else
      putchar(c);
  }
  return EXIT_SUCCESS;
}
