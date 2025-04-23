#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10
#define IN 1
#define OUT 0

int main() {
  int lengths[MAX_WORDS];

  for (int i = 0; i < MAX_WORDS; ++i)
    lengths[i] = 0;

  int c, count, state;
  count = 0; // Word count
  state = OUT;

  while ((c = getchar()) != EOF && count <= MAX_WORDS) {
    // Count letters only
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
      state = IN;
      ++lengths[count];
    } else if (state == IN) {
      state = OUT;
      ++count;
    }
  }

  // Horizontal histogram

  int length = 0;
  for (int i = 0; i < MAX_WORDS; ++i) {
    length = lengths[i];
    if (length == 0)
      continue;
    while (length > 0) {
      printf("|");
      --length;
    }
    printf("\n");
  }

  // Vertical histogram

  int max_value = 0;
  for (int i = 0; i < MAX_WORDS; ++i)
    if (lengths[i] > max_value)
      max_value = lengths[i];

  for (int i = max_value; i > 0; --i) {
    for (int j = 0; j < MAX_WORDS; ++j) {
      if (lengths[j] >= i)
        printf("-");
      else
        printf(" ");
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}
