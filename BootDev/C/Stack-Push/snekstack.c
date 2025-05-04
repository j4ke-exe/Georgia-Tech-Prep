#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct Stack {
  size_t count;
  size_t capacity;
  void **data;
} stack_t;

stack_t *stack_new(size_t capacity);
void stack_push(stack_t *stack, void *obj);

void stack_push(stack_t *stack, void *obj) {
    assert(stack != NULL);

    if (stack->count == stack->capacity) {
        size_t new_capacity = (stack->capacity == 0) ? 1 : stack->capacity * 2;
        size_t new_size_in_bytes = new_capacity * sizeof(void *);
        if (new_capacity > 0 && new_size_in_bytes / new_capacity != sizeof(void *)) {
             exit(EXIT_FAILURE);
        }
        void **temp_data = realloc(stack->data, new_size_in_bytes);
        if (temp_data == NULL) {
            exit(EXIT_FAILURE);
        } else {
            stack->data = temp_data;
            stack->capacity = new_capacity;
        }
    }
    stack->data[stack->count] = obj;
    stack->count++;
}

// don't touch below this line

stack_t *stack_new(size_t capacity) {
  stack_t *stack = malloc(sizeof(stack_t));
  if (stack == NULL) {
    return NULL;
  }

  stack->count = 0;
  stack->capacity = capacity;
  stack->data = malloc(stack->capacity * sizeof(void *));
  if (stack->data == NULL) {
    free(stack);
    return NULL;
  }
  return stack;
}
