#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *str) {
  char buffer[10];
  //strcpy(buffer, str); <- vulnerable
  strncpy(buffer, str, sizeof(buffer) - 1); //use strncpy to specify max number of characters to copy (9 char)
  buffer[sizeof(buffer) - 1] = '\0'; //add null terminator (1 char)
  printf("Buffer content: %s\n", buffer);
}

int main() {
  char input[50];
  printf("Enter a string: ");
  scanf("%10s", input); //limit input to 10 characters
  vulnerableFunction(input);
  return 0;
}
