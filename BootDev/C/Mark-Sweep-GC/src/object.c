#include "object.h"
#include <stdlib.h>

void object_free(object_t *obj) {
  if (obj == NULL) {
    return;
  }

  switch (obj->kind) {
    case STRING:
      free(obj->data.v_string);
      break;
    case ARRAY:
      free(obj->data.v_array.elements);
      break;
    case INTEGER:
    case FLOAT:
    case VECTOR3:
    default:
      break;
  }

  free(obj);
}
