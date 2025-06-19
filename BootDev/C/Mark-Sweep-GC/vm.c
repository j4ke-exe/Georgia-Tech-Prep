#include "vm.h"
#include "object.h"
#include "stack.h"
#include <stdlib.h>

void mark(vm_t *vm) {
  for (size_t i = 0; i < vm->frames->count; i++) {
    frame_t *frame = vm->frames->data[i];
    for (size_t j = 0; j < frame->references->count; j++) {
      object_t *obj = frame->references->data[j];
      obj->is_marked = true;
    }
  }
}

void frame_reference_object(frame_t *frame, object_t *obj) {
  stack_push(frame->references, obj);
}

vm_t *vm_new(void) {
  vm_t *vm = malloc(sizeof(vm_t));
  if (vm == NULL) {
    return NULL;
  }

  vm->frames = stack_new(8);
  vm->objects = stack_new(8);
  return vm;
}

void vm_free(vm_t *vm) {
  if (vm == NULL) {
    return;
  }

  for (size_t i = 0; i < vm->frames->count; i++) {
    frame_free(vm->frames->data[i]);
  }
  stack_free(vm->frames);

  for (size_t i = 0; i < vm->objects->count; i++) {
    object_free(vm->objects->data[i]);
  }
  stack_free(vm->objects);

  free(vm);
}

void vm_frame_push(vm_t *vm, frame_t *frame) { stack_push(vm->frames, frame); }

frame_t *vm_new_frame(vm_t *vm) {
  frame_t *frame = malloc(sizeof(frame_t));
  if (frame == NULL) {
    return NULL;
  }
  frame->references = stack_new(8);
  vm_frame_push(vm, frame);
  return frame;
}

void frame_free(frame_t *frame) {
  if (frame == NULL) {
    return;
  }
  stack_free(frame->references);
  free(frame);
}

void vm_track_object(vm_t *vm, object_t *obj) { stack_push(vm->objects, obj); }