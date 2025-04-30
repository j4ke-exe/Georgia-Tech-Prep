#include <string.h>
#include "exercise.h"

int smart_append(TextBuffer* dest, const char* src) {
  if (dest == NULL || src == NULL) {
    return 1;
  }
  
  const int BUFFER_SIZE = 64;
  size_t src_len = strlen(src);
  size_t available_space = BUFFER_SIZE - dest->length - 1;

  if (src_len > available_space) {
    strncat(dest->buffer, src, available_space);
    dest->length = BUFFER_SIZE - 1;
    return 1;
  } else {
    strcat(dest->buffer, src);
    dest->length += src_len;
    return 0;
  }
}
