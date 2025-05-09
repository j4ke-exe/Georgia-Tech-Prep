"""
Given a base-10 integer, , convert it to binary (base-2). Then find and print the base-10 integer denoting the maximum number
of consecutive 1's in n's binary representation. When working with different bases, it is common to show the base as a subscript.

Example:
  n = 125
  Print a single base-10 integer that denotes the maximum number of consecutive 1's in the binary representation of n.
"""

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    n = int(input().strip())
    
    binary_string = bin(n)[2:]
    
    max_count = 0
    count = 0
    
    for digit in binary_string:
        if digit == "1":
            count += 1
        else:
            if count > max_count:
                max_count = count
            count = 0
            
    if count > max_count:
        max_count = count
        
    print(max_count)
