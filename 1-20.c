#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000
#define TAB_SIZE 4

int getln(char s[], int lim) {
  long int i;
  int c;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

void detab(char input[], char output[]) {
  int i, j, nblanks;

  for (i = j = 0; input[i] != '\0'; ++i)
    if (input[i] == '\t') {

      nblanks = TAB_SIZE - (j % TAB_SIZE);

      while (--nblanks > 0)
        output[++j] = ' ';
    } else
      output[++j] = input[i];

  output[j] = '\0';
}

int main() {
  char input[MAXLENGTH];
  char output[MAXLENGTH];

  while (getln(input, MAXLENGTH) > 0) {
    detab(input, output);
    printf("%s", output);
  }

  return EXIT_SUCCESS;
}
