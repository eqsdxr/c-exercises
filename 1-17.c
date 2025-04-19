#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define THRESHOLD 80

int getln(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
  char line[MAXLINE];
  int len;
  int next_len;

  while ((len = getln(line, MAXLINE)) > 0) {
    if (len > THRESHOLD) {
      printf("%s", line);
      if (len > MAXLINE - 1) {
        next_len = len;
        while ((next_len == MAXLINE - 1) > 0) {
          next_len = getln(line, MAXLINE);
          printf("%s", line);
        }
        if (next_len > 0)
          printf("%s", line);
      }
    }
  }
  return EXIT_SUCCESS;
}

int getln(char s[], int lim)
{
  long int i;
  int c;

  for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
      s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
