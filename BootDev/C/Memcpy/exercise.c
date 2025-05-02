#include <stdlib.h>
#include <string.h>

void swap(void *vp1, void *vp2, size_t size) {
  int* buffer = (int*)malloc(size); // set memory allocation equal to size and assign to buffer
    if (buffer == NULL) {
      return;
    }
  memcpy(buffer, vp1, size); // moves vp1 into buffer
  memcpy(vp1, vp2, size); // moves vp2 into vp1
  memcpy(vp2, buffer, size); // moves buffer into vp2
  free(buffer); // free temporary buffer
}
