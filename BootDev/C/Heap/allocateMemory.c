#include <stdio.h>
#include <stdlib.h>

char* get_full_greeting(char *greeting, char *name, int size);

char *get_full_greeting(char *greeting, char *name, int size) {
  char *full_greeting = (char*)malloc(size);
  if (full_greeting == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1); 
  }
  snprintf(full_greeting, size, "%s %s", greeting, name);
  return full_greeting;
}
