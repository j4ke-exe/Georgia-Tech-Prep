/*
Complete the code in the editor below. The variables , , and  are already declared and initialized for you. You must:

Declare  variables: one of type int, one of type double, and one of type String.
Read  lines of input from stdin (according to the sequence given in the Input Format section below) and initialize your  variables.
Use the  operator to perform the following operations:
Print the sum of  plus your int variable on a new line.
Print the sum of  plus your double variable to a scale of one decimal place on a new line.
Concatenate  with the string you read as input and print the result on a new line.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    int a;
    double b;
    char c[128];
    
    scanf("%d", &a);
    scanf("%lf", &b);
    scanf(" %[^\n]", c); // Skip leading whitespace, then read characters until a newline is encountered.
    
    int sum_a = i + a;
    double sum_b = d + b;
    
    printf("%d\n", sum_a);
    printf("%.1f\n", sum_b);
    printf("%s%s", s, c);

    return 0;
