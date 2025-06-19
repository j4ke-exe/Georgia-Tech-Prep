#include "stack.h"
#include <assert.h>
#include <stdlib.h>

void stack_push(stack_t *stack, void *obj) {
  assert(stack != NULL);
  assert(obj != NULL);

  if (stack->count == stack->capacity) {
    stack->capacity = stack->capacity == 0 ? 1 : stack->capacity * 2;
    stack->data = realloc(stack->data, stack->capacity * sizeof(void *));
    if (stack->data == NULL) {
      exit(1);
    }
  }

  stack->data[stack->count] = obj;
  stack->count++;
}

void *stack_pop(stack_t *stack) {
  assert(stack != NULL);

  if (stack->count == 0) {
    return NULL;
  }

  stack->count--;
  return stack->data[stack->count];
}

void stack_free(stack_t *stack) {
  if (stack == NULL) {
    return;
  }
  free(stack->data);
  free(stack);
}

void stack_remove_nulls(stack_t *stack) {
  assert(stack != NULL);

  size_t new_count = 0;
  for (size_t i = 0; i < stack->count; ++i) {
    if (stack->data[i] != NULL) {
      stack->data[new_count++] = stack->data[i];
    }
  }
  stack->count = new_count;
}

stack_t *stack_new(size_t capacity) {
  stack_t *stack = malloc(sizeof(stack_t));
  if (stack == NULL) {
    return NULL;
  }

  stack->count = 0;
  stack->capacity = capacity;
  if (capacity == 0) {
    stack->data = NULL;
  } else {
    stack->data = malloc(stack->capacity * sizeof(void *));
    if (stack->data == NULL) {
      free(stack);
      return NULL;
    }
  }

  return stack;
}