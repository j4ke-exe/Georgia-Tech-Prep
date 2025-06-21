#include <stdio.h>
#include "vm.h"
#include "new.h"

int main(int argc, char *argv[]) {
  printf("Mark-Sweep GC Demo\n");

  vm_t *vm = vm_new();
  if (vm == NULL) {
    fprintf(stderr, "Error: Could not create VM.\n");
    return 1;
  }
  printf("VM created.\n");

  frame_t *frame = vm_new_frame(vm);
  printf("Root frame created.\n");

  object_t *num1 = new_integer(vm, 123);
  object_t *str1 = new_string(vm, "hello world");

  frame_reference_object(frame, num1);
  frame_reference_object(frame, str1);

  printf("Created and referenced an integer and a string.\n");
  printf("Total objects tracked by VM: %zu\n", vm->objects->count);

  vm_free(vm);
  printf("VM freed. Program finished.\n");

  return 0;
}
