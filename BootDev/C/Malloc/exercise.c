#include <stdio.h>
#include <stdlib.h>

int *allocate_scalar_array(int size, int multiplier);

int *allocate_scalar_array(int size, int multiplier) {
  int *result = (int*)malloc(size * sizeof(int));
  if (result == NULL) {
    return NULL;
  }
  for (int i = 0; i <= size-1; i++) {
    result[i] = i * multiplier;
  }
  return result;
}
