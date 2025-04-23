#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("------------------------\n");
  printf("| Fahrenheit | Celsius |\n");
  printf("------------------------\n");

  for (int fahr = 300; fahr >= 0; fahr = fahr - 20) {
    printf("        %4.f      %4.1f\n", (float)fahr, (9.0 / 5.0 * fahr + 32));
  }

  return EXIT_SUCCESS;
}
