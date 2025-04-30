#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

bool remove_multiple_line_comments(char s[], int len) {
  int i = 0;

  while (s[i] != '\0') {
    if (s[i] == '/' && s[i + 1] == '*') {
      if (i > 0 && s[i - 1] == '\\')
        continue;
      else {
        s[i] = '\0';
        return true;
      }
    } else if (s[i] == '*' && s[i + 1] == '/') {
      if (i > 0 && s[i - 1] == '\\')
        continue;
      char reminder[len - i + 1];
      int m = i;
      for (int j = 0; j < len - m; ++j) {
        reminder[j] = s[m];
        ++m;
      }
      reminder[m] = '\0';

      for (int j = 0; j < len - i; ++j) {
        s[i] = reminder[j];
        ++i;
      }
      return false;
    }
    ++i;
  }
  return false;
}

void remove_one_line_comments(char s[], int len) {
  bool in_quotes = false;

  int i = 0;

  while (s[i] != '\0') {
    if (s[i] == '"' || s[i] == '\'' && in_quotes == false) {
      in_quotes = true;
    } else if (s[i] == '"' ||
               s[i] == '\'' && in_quotes == true && s[i - 1] != '\\') {
      in_quotes = false;
    } else if (s[i] == '/' && s[i + 1] == '/') {
      if (in_quotes == true)
        continue;
      else {
        s[i] = '\0';
        break;
      }
    }
    ++i;
  }
}

int main() {

  int len;
  char line[MAXLEN];

  while ((len = read_line(line, MAXLEN)) > 0) {
    while ((remove_multiple_line_comments(line, len)) == true)
      ;
    remove_one_line_comments(line, len);
    printf("%s\n", line);
  }

  return EXIT_SUCCESS;
}
