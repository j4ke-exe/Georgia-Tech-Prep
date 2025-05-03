/*
Example:
  n = 3
  k = 3

The results of the comparisons are below:
  a b   and or xor
  1 2   0   3  3
  1 3   1   3  2
  2 3   2   3  1

For the and comparison, the maximum is 2. For the or comparison, none of the values is less than k, so the maximum is 0.
For the xor comparison, the maximum value less than k is 2. The function should print:
  2
  0
  2

Function Description:
  Complete the calculate_the_maximum function in the editor below.

calculate_the_maximum has the following parameters:
  int n: the highest number to consider
  int k: the result of a comparison must be lower than this number to be considered
  
Prints:
  Print the maximum values for the and, or and xor comparisons, each on a separate line.

Input Format:
  The only line contains 2 space-separated integers, n and k.

Constraints:
  2 <= n <= 10^3
  2 <= k <= n
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k) {
    int max_and = 0;
    int max_or = 0;
    int max_xor = 0;
    
    for (int a = 1; a < n; a++) {
        for (int b = a + 1; b <= n; b++) {
            int _and = a & b;
            int _or = a | b;
            int _xor = a ^ b;
            
            if (_and < k && _and > max_and) {
                max_and = _and;
            }
            if (_or < k && _or > max_or) {
                max_or = _or;
            }
            if (_xor < k && _xor > max_xor) {
                max_xor = _xor;
            }
        }
    }
    printf("%d\n", max_and);
    printf("%d\n", max_or);
    printf("%d\n", max_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
