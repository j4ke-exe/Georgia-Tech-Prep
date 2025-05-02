#include "stack.h"
#include <stdlib.h>

stack_t *stack_new(size_t capacity) {
  stack_t *my_stack = (stack_t *)malloc(sizeof(my_stack));
  if (my_stack == NULL) {
    return NULL;
  }
  
  void **data_buffer = (void **)malloc(capacity * sizeof(void *));
  if (data_buffer == NULL) {
    return NULL;
    free(data_buffer);
  }
  
  my_stack->count = 0;
  my_stack->capacity = capacity;
  my_stack->data = data_buffer;

  return my_stack;
}
