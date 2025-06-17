#include "objects.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

// Decrement Reference Counter
void refcount_dec(object_t *obj)
{
   if (!obj)
      return;
   obj->refcount--;
   if (!obj->refcount)
      refcount_free(obj);
}

// Free Reference Counter
void refcount_free(object_t *obj)
{
   switch (obj->type)
   {
   case INTEGER:
   case FLOAT:
      break;
   case STRING:
      free(obj->data.v_string);
      break;
   case ARRAY:
      for (size_t i = 0; i < obj->data.v_array.size; i++)
      {
         if (obj->data.v_array.items[i] != NULL)
         {
            refcount_dec(obj->data.v_array.items[i]);
         }
      }
      free(obj->data.v_array.items);
      break;
   case VECTOR3:
   {
      refcount_dec(obj->data.v_vector3.x);
      refcount_dec(obj->data.v_vector3.y);
      refcount_dec(obj->data.v_vector3.z);
      break;
   }
   default:
      assert(false);
   }
   free(obj);
}

// Increment Reference Counter
void refcount_inc(object_t *obj)
{
   if (!obj)
      return;
   obj->refcount++;
}

// Reference Counter
object_t *_new_object()
{
   object_t *obj = calloc(1, sizeof(object_t));
   if (!obj)
      return NULL;
   obj->refcount = 1;
   return obj;
}

// Adds Two Objects Based On Type
object_t *add(object_t *a, object_t *b)
{
   if (!a || !b)
      return NULL;

   // Add Integer
   if (a->type == INTEGER)
   {
      if (b->type == INTEGER)
         return new_integer(a->data.v_int + b->data.v_int);
      else if (b->type == FLOAT)
         return new_float(a->data.v_int + b->data.v_float);
      else
         return NULL;

      // Add Float
   }
   else if (a->type == FLOAT)
   {
      if (b->type == INTEGER)
         return new_float(a->data.v_float + b->data.v_int);
      else if (b->type == FLOAT)
         return new_float(a->data.v_float + b->data.v_float);
      else
         return NULL;

      // String Concatenation
   }
   else if (a->type == STRING)
   {
      if (b->type != STRING)
         return NULL;
      size_t a_len = strlen(a->data.v_string);
      size_t b_len = strlen(b->data.v_string);
      size_t total_len = a_len + b_len + 1;

      // Allocate Memory For Concatenated String
      char *temp = calloc(total_len, sizeof(char));
      if (!temp)
         return NULL;

      strcpy(temp, a->data.v_string);
      strcat(temp, b->data.v_string);

      object_t *result = new_string(temp);
      free(temp);
      return result;

      // Vector3 Addition (Element)
   }
   else if (a->type == VECTOR3)
   {
      if (b->type != VECTOR3)
         return NULL;
      return new_vector3(
          add(a->data.v_vector3.x, b->data.v_vector3.x),
          add(a->data.v_vector3.y, b->data.v_vector3.y),
          add(a->data.v_vector3.z, b->data.v_vector3.z));

      // Array Concatenation
   }
   else if (a->type == ARRAY)
   {
      if (b->type != ARRAY)
         return NULL;
      size_t a_size = a->data.v_array.size;
      size_t b_size = b->data.v_array.size;
      object_t *result = new_array(a_size + b_size);

      // Copy Elements From Array 'a'
      for (size_t i = 0; i < a_size; i++)
      {
         array_set(result, i, array_get(a, i));
      }

      // Copy Elements From Array 'b'
      for (size_t i = 0; i < b_size; i++)
      {
         array_set(result, i + a_size, array_get(b, i));
      }

      return result;
   }

   return NULL;
}

// Returns Logical Length
int length(object_t *obj)
{
   if (!obj)
      return -1;

   switch (obj->type)
   {
   case INTEGER:
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

// Sets Index Value
bool array_set(object_t *obj, size_t index, object_t *value)
{
   if (!obj || !value || obj->type != ARRAY || index >= obj->data.v_array.size)
      return false;

   object_t *old_item = obj->data.v_array.items[index];

   if (old_item != NULL)
   {
      refcount_dec(old_item);
   }

   obj->data.v_array.items[index] = value;

   if (value != NULL)
   {
      refcount_inc(value);
   }

   return true;
}

// Retrieves Index Value
object_t *array_get(object_t *obj, size_t index)
{
   if (!obj || obj->type != ARRAY || index >= obj->data.v_array.size)
      return NULL;

   return obj->data.v_array.items[index];
}

// New Array Object
object_t *new_array(size_t size)
{
   object_t *obj = malloc(sizeof(object_t));
   if (!obj)
      return NULL;

   object_t **items = calloc(size, sizeof(object_t *));
   if (!items)
   {
      free(obj);
      return NULL;
   }

   obj->type = ARRAY;
   obj->data.v_array.size = size;
   obj->data.v_array.items = items;
   return obj;
}

// New Vector3 Object
object_t *new_vector3(object_t *x, object_t *y, object_t *z)
{
   if (!x || !y || !z)
      return NULL;

   object_t *obj = malloc(sizeof(object_t));
   if (!obj)
      return NULL;

   obj->type = VECTOR3;
   obj->data.v_vector3.x = x;
   obj->data.v_vector3.y = y;
   obj->data.v_vector3.z = z;
   refcount_inc(obj->data.v_vector3.x);
   refcount_inc(obj->data.v_vector3.y);
   refcount_inc(obj->data.v_vector3.z);

   return obj;
}

// New String Object
object_t *new_string(char *value)
{
   if (!value)
      return NULL;

   object_t *obj = malloc(sizeof(object_t));
   if (!obj)
      return NULL;

   char *copy = malloc(strlen(value) + 1);
   if (!copy)
   {
      free(obj);
      return NULL;
   }

   strcpy(copy, value);
   obj->type = STRING;
   obj->data.v_string = copy;
   return obj;
}

// Integer Object
object_t *new_integer(int value)
{
   object_t *obj = malloc(sizeof(object_t));
   if (!obj)
      return NULL;

   obj->type = INTEGER;
   obj->data.v_int = value;
   return obj;
}

// Float Object
object_t *new_float(float value)
{
   object_t *obj = malloc(sizeof(object_t));
   if (!obj)
      return NULL;

   obj->type = FLOAT;
   obj->data.v_float = value;
   return obj;
}

// Sample Case
int main()
{
   object_t *a = new_integer(5);
   object_t *b = new_float(3.2);
   object_t *result = add(a, b);

   if (result && result->type == FLOAT)
   {
      printf("Result: %.2f\n", result->data.v_float);
   }

   return 0;
}
