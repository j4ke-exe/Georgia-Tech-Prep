#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printUserInput(char *userInput, char *secretPassword, int secretNumber)
{
  printf("\n[Output]\n");
  //printf(userInput); // Vulnerability: User input is used as the format string
  printf("%s", userInput); // Mitigates vulnerability by using %s format
  printf("\n");
}

int main()
{
  char input[100];
  // Secret data stored in variables
  char secretPassword[] = "SuperSecret123";
  int secretNumber = 42;

  printf("Enter your name: ");
  // Read user input and remove the trailing newline character
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';

  // Call the vulnerable function
  printUserInput(input, secretPassword, secretNumber);

  return 0;
}
