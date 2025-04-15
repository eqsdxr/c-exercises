#include <stdio.h>
#include <stdlib.h>

int ftoc(int f);

int main()
{
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
    celsius = ftoc(fahr);
    printf("          %3.0f     %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }


  return EXIT_SUCCESS;
}

int ftoc(int f)
{
  return (5.0/9.0) * (f-32.0);
}
