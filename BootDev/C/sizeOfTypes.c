#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main() {
  // Use %zu is for printing `sizeof` result
  printf("sizeof(char)    = %zu\n", sizeof(char));
  printf("sizeof(bool)    = %zu\n", sizeof(bool));
  printf("sizeof(int)     = %zu\n", sizeof(int));
  printf("sizeof(float)   = %zu\n", sizeof(float));
  printf("sizeof(double)  = %zu\n", sizeof(double));
  printf("sizeof(size_t)  = %zu\n", sizeof(size_t));
}
