/*
Task:
  Given a string, S, of length N that is indexed from 0 to N-1, print its even-indexed and odd-indexed 
  characters as 2 space-separated strings on a single line.

Note:
  0 is considered to be an even index.

Example:
  s = adbecf

Print:
  abc def

Input Format:
  The first line contains an integer, T (the number of test cases).
  Each line i of the T subsequent lines contain a string, S.

Constraints:
  1 <= T <= 10
  2 <= length of S <= 10000
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int cases; // Number of test cases

    if (scanf("%d", &cases) != 1) {
        return 1;
    }

    getchar(); // Remove newline character left by scanf

    for (int i = 0; i < cases; i++) {
        char buffer[10010];  // Buffer for the input string
        char even_str[5010]; // Stores characters at even indices
        char odd_str[5010];  // Stores characters at odd indices
        int even_index = 0;  // Current index for even_str
        int odd_index = 0;   // Current index for odd_str

        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline character from fgets input

            size_t input_len = strlen(buffer);
            for (int j = 0; j < input_len; j++) {
                if (j % 2 == 0) { // Check if the character index is even
                    if (even_index < sizeof(even_str) - 1) {
                        even_str[even_index++] = buffer[j]; // Add character to even_str
                    }
                } else {
                    if (odd_index < sizeof(odd_str) - 1) {
                        odd_str[odd_index++] = buffer[j]; // Add character to odd_str
                    }
                }
            }
            // Null-terminate the separated strings
            even_str[even_index] = '\0';
            odd_str[odd_index] = '\0';

            printf("%s %s\n", even_str, odd_str);
        }
    }
    return 0;
}
