#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdbool.h>
#include <stddef.h>

// Object types
typedef enum {
    INTEGER,
    FLOAT,
    STRING,
    VECTOR3,
    ARRAY
} object_type_t;

// Forward declaration
typedef struct Object object_t;

// 3D vector
typedef struct {
    object_t *x;
    object_t *y;
    object_t *z;
} vector3_t;

// Dynamic array
typedef struct {
    size_t size;
    object_t **items;
} array_t;

// Object structure
struct Object {
    object_type_t type;
    union {
        int v_int;
        float v_float;
        char *v_string;
        vector3_t v_vector3;
        array_t v_array;
    } data;
};

// Constructors
object_t *new_integer(int value);
object_t *new_float(float value);
object_t *new_string(char *value);
object_t *new_vector3(object_t *x, object_t *y, object_t *z);
object_t *new_array(size_t size);

// Array Access
object_t *array_get(object_t *obj, size_t index);
bool array_set(object_t *obj, size_t index, object_t *value);

// Operations
object_t *add(object_t *a, object_t *b);
int length(object_t *obj);

#endif
