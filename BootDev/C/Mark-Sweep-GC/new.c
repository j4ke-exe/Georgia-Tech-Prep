#include "new.h"
#include "object.h"
#include "vm.h"
#include <stdlib.h>
#include <string.h>

static object_t *_new_object(vm_t *vm) {
  object_t *obj = calloc(1, sizeof(object_t));
  if (obj == NULL) {
    return NULL;
  }

  vm_track_object(vm, obj);
  obj->is_marked = false;
  return obj;
}

object_t *new_array(vm_t *vm, size_t size) {
  object_t *obj = _new_object(vm);
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = ARRAY;
  obj->data.v_array.size = size;
  obj->data.v_array.elements = calloc(size, sizeof(object_t *));
  if (obj->data.v_array.elements == NULL) {
    free(obj);
    return NULL;
  }

  return obj;
}

object_t *new_vector3(vm_t *vm, object_t *x, object_t *y, object_t *z) {
  if (x == NULL || y == NULL || z == NULL) {
    return NULL;
  }

  object_t *obj = _new_object(vm);
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = VECTOR3;
  obj->data.v_vector3.x = x;
  obj->data.v_vector3.y = y;
  obj->data.v_vector3.z = z;

  return obj;
}

object_t *new_integer(vm_t *vm, int value) {
  object_t *obj = _new_object(vm);
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = INTEGER;
  obj->data.v_int = value;

  return obj;
}

object_t *new_float(vm_t *vm, float value) {
  object_t *obj = _new_object(vm);
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}

object_t *new_string(vm_t *vm, const char *value) {
  object_t *obj = _new_object(vm);
  if (obj == NULL) {
    return NULL;
  }

  size_t len = strlen(value);
  char *dst = malloc(len + 1);
  if (dst == NULL) {
    free(obj);
    return NULL;
  }
  memcpy(dst, value, len + 1);

  obj->kind = STRING;
  obj->data.v_string = dst;
  return obj;
}