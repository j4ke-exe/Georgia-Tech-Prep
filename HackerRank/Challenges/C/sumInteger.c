// Given a five digit integer, n, print the sum of its digits.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    
    int sum = 0;
    
    while (n > 0) {
        int last_digit = n % 10; // To get the last digit of a number in base 10, use 10 as the modulo divisor.
        sum += last_digit;
        n /= 10; // Divide by 10 to remove the last digit
    }
    
    printf("%d", sum);
    
    return 0;
}
