#include <stdio.h>
#include <stdlib.h>

#define HARD_LIMIT 80
#define MAXLEN 1000

int read_line(char str[], int maxlen) {

  int c, i;

  i = 0;

  while ((c = getchar()) != EOF && c != '\n' && i < maxlen - 1) {
    str[i] = c;
    ++i;
  }

  str[i] = '\0';

  return i;
}

void fold_line(char str[], int len, int limit) {

  int j, last_blank;

  for (int i = j = 0; str[i] != '\0'; ++i) {
    // When hard limit is exceeded
    if (j > limit) {
      if (last_blank) {
        str[last_blank] = '\n';
        last_blank = 0;
      } else {
        str[i] = '\n';
        j = 0;
      }
    } else {
      if (str[i] == ' ' || str[i] == '\t') {
        last_blank = i;
      }
    }
    ++j;
  }
}

int main() {

  int len;
  char line[MAXLEN];

  while ((len = read_line(line, MAXLEN)) > 0) {
    if (len > HARD_LIMIT) {
      fold_line(line, len, HARD_LIMIT);
      printf("%s", line);
    } else {
      printf("%s", line);
    }
  }

  return EXIT_SUCCESS;
}
