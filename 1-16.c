#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 10000

int getln(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  long int length;
  int next_length;
  long int max;
  char ln[MAXLINE];
  char next_ln[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((length = getln(ln, MAXLINE)) > 0) {
    if (length > MAXLINE - 1) {
      ln[MAXLINE - 1] = '\n';
      next_length = length;
      while (next_length == MAXLINE - 1) {
        next_length = getln(next_ln, MAXLINE);
        length += next_length;
      }
    }
    if (length > max) {
      max = length;
      copy(longest, ln);
    }
  }
  if (max > 0)
    printf("%ld %s", max, longest);
  return EXIT_SUCCESS;
}

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

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
