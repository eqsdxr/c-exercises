#include <stdio.h>
#include <stdlib.h>

#define AMOUNT_OF_SYMBOLS 127

int main()
{
  int chars[AMOUNT_OF_SYMBOLS];

  int c;

  int total_chars = 0;

  for (int i = 0; i < AMOUNT_OF_SYMBOLS; ++i)
    chars[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c < 0 || c > AMOUNT_OF_SYMBOLS) {
      printf("An illigal character registered: %c", c);
      return EXIT_FAILURE;
    }
    ++chars[c];
    ++total_chars;
  }

  int amount = 0;
  for (int i = 0; i < AMOUNT_OF_SYMBOLS; ++i) {
    printf("%3d", i);
    amount = chars[i];
    while (amount > 0) {
      printf("|");
      --amount;
    }
    printf("\n");
  }

  printf("Total characters: %d\n", total_chars);

  return EXIT_SUCCESS;
}

