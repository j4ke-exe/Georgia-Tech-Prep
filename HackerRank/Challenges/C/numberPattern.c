/*
Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space.

                            4 4 4 4 4 4 4  
                            4 3 3 3 3 3 4   
                            4 3 2 2 2 3 4   
                            4 3 2 1 2 3 4   
                            4 3 2 2 2 3 4   
                            4 3 3 3 3 3 4   
                            4 4 4 4 4 4 4   
Input Format:
  The input will contain a single integer n.

Constraints:
  1 <= n <= 1000
  
Sample Input:
  2
  
Sample Output:
  2 2 2
  2 1 2
  2 2 2
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int minimum(int a, int b) {
    return (a < b) ? a : b;
}

typedef struct EdgeDistances{
    int top;
    int bottom;
    int left;
    int right;
} edge_t;

int main() {
    int n;
    scanf("%d", &n);
    
    int grid_size = 2 * n - 1;
    
    for (int row = 0; row <= grid_size - 1; row++) {
        for (int column = 0; column <= grid_size - 1; column++) {
            
            edge_t dist;
            dist.top = row;
            dist.bottom = (grid_size - 1) - row;
            dist.left = column;
            dist.right = (grid_size - 1) - column;
            
            int min_dist_vert = minimum(dist.top, dist.bottom);
            int min_dist_hori = minimum(dist.left, dist.right);
            int min_dist = minimum(min_dist_vert, min_dist_hori);
            
            int val_to_print = n - min_dist;
            printf("%d ", val_to_print);
        }
        printf("\n");
    }
    return 0;
}
