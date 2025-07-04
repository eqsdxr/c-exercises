#include <stdio.h>
#include <stdlib.h>

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  printf("------------------------\n");
  printf("| Fahrenheit | Celsius |\n");
  printf("------------------------\n");
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("          %3.0f     %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return EXIT_SUCCESS;
}
