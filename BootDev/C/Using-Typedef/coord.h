#pragma once

typedef struct Coordinate { // Initiliaze typedef coordinate_t
  int x;
  int y;
  int z;
} coordinate_t;

struct Coordinate new_coord(int x, int y, int z);
struct Coordinate scale_coordinate(struct Coordinate coord, int factor);
