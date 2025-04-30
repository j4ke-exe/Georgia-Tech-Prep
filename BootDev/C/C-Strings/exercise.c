#include "exercise.h"

// Without using strcat
void concat_strings(char *str1, const char *str2) {
  int i = 0;
  int j = 0;
  while (str1[i] != '\0') {
    i++;
  }
  do {
    str1[i] = str2[j];
    i++;
    j++;
  } while (str2[j-1] != '\0');
}
