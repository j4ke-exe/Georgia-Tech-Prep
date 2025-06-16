#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct Object object_t;

typedef enum ObjectKind
{
   INTEGER,
   FLOAT,
   STRING,
   VECTOR3,
   ARRAY,
} object_kind_t;

typedef struct Vector
{
   object_t *x;
   object_t *y;
   object_t *z;
} vector_t;

typedef struct Array
{
   size_t size;
   object_t **elements;
} array_t;

typedef union ObjectData
{
   int v_int;
   float v_float;
   char *v_string;
   vector_t v_vector3;
   array_t v_array;
} object_data_t;

typedef struct Object
{
   object_kind_t kind;
   object_data_t data;
} object_t;

object_t *add(object_t *a, object_t *b)
{
   if (a == NULL || b == NULL)
   {
      return NULL;
   }

   if (a->kind == INTEGER)
   {
      if (b->kind == INTEGER)
      {
         return new_integer(a->data.v_int + b->data.v_int);
      }
      else if (b->kind == FLOAT)
      {
         return new_float(a->data.v_int + b->data.v_float);
      }
      else
      {
         return NULL;
      }
   }
   else if (a->kind == FLOAT)
   {
      if (b->kind == INTEGER)
      {
         return new_float(a->data.v_float + b->data.v_int);
      }
      else if (b->kind == FLOAT)
      {
         return new_float(a->data.v_float + b->data.v_float);
      }
      else
      {
         return NULL;
      }
   }
   else if (a->kind == STRING)
   {
      if (b->kind != STRING)
      {
         return NULL;
      }
      int a_len = strlen(a->data.v_string);
      int b_len = strlen(b->data.v_string);
      int total_len = a_len + b_len + 1;
      char *temp_string = calloc(total_len, sizeof(char));
      strcat(temp_string, a->data.v_string);
      strcat(temp_string, b->data.v_string);
      object_t *result = new_string(temp_string);
      free(temp_string);
      temp_string = NULL;
      return result;
   }
   else if (a->kind == VECTOR3)
   {
      if (b->kind != VECTOR3)
      {
         return NULL;
      }
      return new_vector3(
          add(a->data.v_vector3.x, b->data.v_vector3.x),
          add(a->data.v_vector3.y, b->data.v_vector3.y),
          add(a->data.v_vector3.z, b->data.v_vector3.z));
   }
   else if (a->kind == ARRAY)
   {
      if (b->kind != ARRAY)
      {
         return NULL;
      }
      size_t a_size = a->data.v_array.size;
      size_t b_size = b->data.v_array.size;
      size_t total_size = a_size + b_size;
      object_t *result = new_array(total_size);

      for (size_t i = 0; i < a_size; i++)
      {
         object_t *element = array_get(a, i);
         array_set(result, i, element);
      }
      for (size_t i = 0; i < b_size; i++)
      {
         object_t *element = array_get(b, i);
         array_set(result, i + a_size, element);
      }
      return result;
   }
   else
   {
      return NULL;
   }
}

int length(object_t *obj)
{
   if (obj == NULL)
   {
      return -1;
   }

   switch (obj->kind)
   {
   case INTEGER:
      return 1;
   case FLOAT:
      return 1;
   case STRING:
      return strlen(obj->data.v_string);
   case VECTOR3:
      return 3;
   case ARRAY:
      return obj->data.v_array.size;
   default:
      return -1;
   }
}

bool array_set(object_t *obj, size_t index, object_t *value)
{
   if (obj == NULL || value == NULL)
   {
      return false;
   }
   if (obj->kind != ARRAY)
   {
      return false;
   }
   if (index > obj->data.v_array.size)
   {
      return false;
   }
   obj->data.v_array.elements[index] = value;
   return true;
}

object_t *array_get(object_t *obj, size_t index)
{
   if (obj == NULL)
   {
      return NULL;
   }
   if (obj->kind != ARRAY)
   {
      return NULL;
   }
   if (index >= obj->data.v_array.size)
   {
      return NULL;
   }
   return obj->data.v_array.elements[index];
}

object_t *new_array(size_t size)
{
   object_t *obj = malloc(sizeof(object_t));
   if (obj == NULL)
   {
      return NULL;
   }

   object_t **elements = calloc(size, sizeof(object_t *));
   if (elements == NULL)
   {
      free(elements);
      return NULL;
   }

   obj->kind = ARRAY;
   obj->data.v_array = (array_t){.size = size, .elements = elements};

   return obj;
}

object_t *new_vector3(object_t *x, object_t *y, object_t *z)
{
   if (x == NULL || y == NULL || z == NULL)
   {
      return NULL;
   }

   object_t *obj = malloc(sizeof(object_t));
   if (obj == NULL)
   {
      return NULL;
   }

   obj->kind = VECTOR3;
   obj->data.v_vector3 = (vector_t){.x = x, .y = y, .z = z};

   return obj;
}

object_t *new_string(char *value)
{
   object_t *obj = malloc(sizeof(object_t));
   if (obj == NULL)
   {
      return NULL;
   }

   char *dst = malloc(strlen(value) + 1);
   if (dst == NULL)
   {
      return NULL;
      free(dst);
   }
   strcpy(dst, value);

   obj->kind = STRING;
   obj->data.v_string = dst;

   return obj;
}

object_t *new_integer(int value)
{
   object_t *obj = malloc(sizeof(object_t));
   if (obj == NULL)
   {
      return NULL;
   }

   obj->kind = INTEGER;
   obj->data.v_int = value;

   return obj;
}

object_t *new_float(float value)
{
   object_t *obj = malloc(sizeof(object_t));
   if (obj == NULL)
   {
      return NULL;
   }

   obj->kind = FLOAT;
   obj->data.v_float = value;

   return obj;
}
