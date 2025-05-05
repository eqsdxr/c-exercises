#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
#define STACK_SIZE 100

int push(char element, int *top, char inp_array[], int stack_size);
int pop(int *top, char inp_array[]);
void run_checks(char s[], int len);

int push(char element, int *top, char inp_array[], int stack_size) {
  if (*top == stack_size - 1)
    return 1;
  else {
    inp_array[++(*top)] = element;
    return 0;
  }
}

int pop(int *top, char inp_array[]) {
  if (*top == -1)
    return 1;
  else {
    return inp_array[(*top)--];
  }
}

void run_checks(char s[], int len) {

  int line_count = 0;
  int i = 0;

  int top = -1;
  char stack[STACK_SIZE];
  for (int j = 0; j < STACK_SIZE; stack[j++] = 0);
  int c = 0;

  // Var to check if "" were unclosed
  bool double_quotes = false;

  for (; s[i] != '\0'; ++i) {

    // Skip everything beyond ASCII
    for (; s[i] > 127; ++i)
      ;

    // Skip double quotes
    if (s[i] == '\"' && (i == 0 || (i > 0 && s[i - 1] != '\\'))) {
      double_quotes = true;
      for (++i; s[i] != '\0'; ++i) {
        if (s[i] == '\"' && s[i - 1] != '\\') {
          double_quotes = false;
          break;
        } else if (s[i] == '\n')
          ++line_count;
      }
      continue;
    }

    // If it's a single-line comment, increase i until it points to \n
    if (s[i] == '/' && s[i + 1] == '/') {
      for (; s[i] != '\n' && s[i] != '\0'; ++i)
        ;
      continue;
    }

    // If it's a multi-line comment, increase i until it points to the end
    if (s[i] == '/' && i > 0 && s[i + 1] == '*') {
      for (; i <= len && s[i] != '/' && s[i - 1] != '*'; ++i) {
        if (s[i] == '\n')
          ++line_count;
      }
      continue;
    }

    // Count and skip new line characters
    if (s[i] == '\n') {
      ++line_count;
      continue;
    }

    // Check single quotes
    if (s[i] == '\'' && ((i > 0 && s[i - 1] != '\\') || i == 0)) {
      if (i + 2 <= len && s[i + 2] == '\'') {
        i += 3;
      } else if (s[i + 1] == '\\' && i + 3 <= len && s[i + 3] == '\'') {
        i += 4;
      } else if (s[i + 1] == '\'') {
        i += 2;
        printf("line: %d - Expected expression in ''\n", line_count);
      } else {
        printf("line: %d - Incorrect usage of single quotes\n", line_count);
      }
    }

    // Check unmatched brackets, braces, and parenthesis
    if (s[i] == '(' && (i == 0 || (s[i - 1] != '\\'))) {
      push(s[i], &top, stack, STACK_SIZE);
    } else if (s[i] == '[' && (i == 0 || (s[i - 1] != '\\'))) {
      push(s[i], &top, stack, STACK_SIZE);
    } else if (s[i] == '{' && (i == 0 || (s[i - 1] != '\\'))) {
      push(s[i], &top, stack, STACK_SIZE);
    } else if (s[i] == ')' && (i == 0 || (s[i - 1] != '\\'))) {
      c = pop(&top, stack);
      if (c != '(') {
        printf("line: %d - Unmatched )\n", line_count);
      }
    } else if (s[i] == ']' && (i == 0 || (s[i - 1] != '\\'))) {
      c = pop(&top, stack);
      if (c != '[') {
        printf("line: %d - Unmatched ]\n", line_count);
      }
    } else if (s[i] == '}' && (i == 0 || (s[i - 1] != '\\'))) {
      c = pop(&top, stack);
      if (c != '{') {
        printf("line: %d - Unmatched }\n", line_count);
      }
    }
  }

  if (double_quotes)
    printf("Unclosed double quotes\n");

  while ((c = pop(&top, stack)) != 1) {
    printf("Unmatched bracket\n");
  }
}

int main() {

  char s[MAXLEN];
  int i, c;
  for (i = 0; (c = getchar()) != EOF && i < MAXLEN - 1; i++)
    s[i] = c;

  s[i] = '\0';

  run_checks(s, i);

  return EXIT_SUCCESS;
}
