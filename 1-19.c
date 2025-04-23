#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getln(char s[], int lim);
void reverse(char s[], int lim);

int main() {
  char line[MAXLINE];
  int len;

  while ((len = getln(line, MAXLINE)) > 0) {
    reverse(line, len);
    for (int i = 0; i < len; ++i) {
      putchar(line[i]);
    }
  }
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

void reverse(char s[], int len) {
  int temp;
  int i = 0;
  int j = len - 1; // Prevent \0 from reversing
  // Prevent \n from reversing
  if (s[j] == '\n') {
    --j;
  }
  while (i < j) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    ++i;
    --j;
  }
}
