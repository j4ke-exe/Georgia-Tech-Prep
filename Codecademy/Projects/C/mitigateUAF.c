#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeAndFreeStrings(char **strArray)
{
  // Initialize the strings
  strcpy(strArray[0], "Hello");
  strcpy(strArray[1], "Codecademy");
  strcpy(strArray[2], "World");

  // Print the strings before freeing
  printf("strArray before free:\n");
  for (int i = 0; i < 3; i++)
  {
    printf("strArray[%d]: %s\n", i, strArray[i]);
  }

  // Free the allocated memory for each string
  for (int i = 0; i < 3; i++)
  {
    free(strArray[i]);  // Dangling pointers
    strArray[i] = NULL; // Set pointers to NULL after freed
  }
}

void demonstrateUseAfterFree()
{
  // Allocate memory for an array of strings (char pointers)
  char **strArray = (char **)malloc(3 * sizeof(char *));
  if (strArray == NULL)
  {
    printf("Memory allocation failed!\n");
    return;
  }

  // Allocate memory for each string
  for (int i = 0; i < 3; i++)
  {
    strArray[i] = (char *)malloc(15 * sizeof(char));
    if (strArray[i] == NULL)
    {
      printf("Memory allocation failed for string %d!\n", i);
      // Free previously allocated memory before returning
      for (int j = 0; j < i; j++)
      {
        free(strArray[j]);
      }
      free(strArray);
      return;
    }
  }

  // Call the function that initializes, prints, and frees the strings
  initializeAndFreeStrings(strArray);

  // Attempt to access the freed memory
  printf("\nstrArray after free (Use-After-Free):\n");
  for (int i = 0; i < 3; i++)
  {
    if (strArray[i] != NULL)
    {
      printf("strArray[%d]: %s\n", i, strArray[i]); // Use-after-free occurs here
    }
    else
    {
      printf("strArray[%d] is NULL\n", i);
    }
  }

  // Allocate new memory to show how freed memory can be overwritten
  char *newData = (char *)malloc(15 * sizeof(char));
  strcpy(newData, "Data Exposure!");
  printf("\nAllocated new memory (newData) with the string: \"%s\"\n", newData);

  // Attempt to access the freed memory again
  printf("\nstrArray after allocating new memory:\n");
  for (int i = 0; i < 3; i++)
  {
    if (strArray[i] != NULL)
    {
      printf("strArray[%d]: %s\n", i, strArray[i]); // Use-after-free occurs here
    }
    else
    {
      printf("strArray[%d] is NULL\n", i);
    }
  }

  // Clean up remaining allocated memory
  free(newData);
  free(strArray);
}

int main()
{
  demonstrateUseAfterFree();
  return 0;
}
