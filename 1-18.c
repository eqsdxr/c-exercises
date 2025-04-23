#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define THRESHOLD 80

int trim_left(char s[], int len);
int trim_right(char s[], int len);
int getln(char s[], int lim);

int main() {
  char line[MAXLINE];
  int len;
  int start;
  int end;

  while ((len = getln(line, MAXLINE)) > 0) {
    if (len == 1 && line[0] == '\n')
      line[0] = '\0';
    start = trim_left(line, len);
    end = trim_right(line, len);
    for (int i = start; i <= end; ++i)
      printf("%c", line[i]);
  }
  return EXIT_SUCCESS;
}

int trim_left(char s[], int len) {
  for (int i = 0; i < len; ++i)
    if (s[i] != ' ' && s[i] != '\t')
      return i;
  return 0;
}

int trim_right(char s[], int len) {
  for (int i = len - 2; i > 0; --i)
    if (s[i] != ' ' && s[i] != '\t') {
      return i + 1;
    }
  return len;
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
