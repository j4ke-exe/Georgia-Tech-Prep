#pragma once

// Initialize typedef coordinate_t (_t is required)
typedef struct Coordinate { // Order from largest to smallest to help the compiler minimize padding
  int x;
  int y;
  int z;
} coordinate_t;

struct Coordinate new_coord(int x, int y, int z);
struct Coordinate scale_coordinate(struct Coordinate coord, int factor);
