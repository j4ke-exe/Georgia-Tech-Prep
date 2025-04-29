#include <stdio.h>
#include "exercise.h"

void dump_graphics(graphics_t gsettings[10]) {
  int *ptr = (int *)gsettings; // Cast the array of structs to an array of integers to iterate over.
  for (int i = 0; i < 30; i++) {
    printf("settings[%d] = %d\n", i, ptr[i]);
  }
}
