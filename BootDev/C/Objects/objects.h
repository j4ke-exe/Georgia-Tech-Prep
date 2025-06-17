#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdbool.h>
#include <stddef.h>

// Object Types
typedef enum
{
   INTEGER,
   FLOAT,
   STRING,
   VECTOR3,
   ARRAY
} object_type_t;

// Forward Declaration
typedef struct Object object_t;

// 3D Vector
typedef struct
{
   object_t *x;
   object_t *y;
   object_t *z;
} vector3_t;

// Dynamic Array
typedef struct
{
   size_t size;
   object_t **items;
} array_t;

// Object Structure
struct Object
{
   object_type_t type;
   int refcount;
   union
   {
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

// Reference Counting Functions
void refcount_inc(object_t *obj);
void refcount_dec(object_t *obj);
void refcount_free(object_t *obj);

// Array Access Functions
object_t *array_get(object_t *obj, size_t index);
bool array_set(object_t *obj, size_t index, object_t *value);

// Operations
object_t *add(object_t *a, object_t *b);
int length(object_t *obj);

#endif
