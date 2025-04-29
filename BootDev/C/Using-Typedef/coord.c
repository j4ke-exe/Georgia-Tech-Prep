#include "coord.h"

coordinate_t new_coord(int x, int y, int z) { // Instead of struct Coordinate new_coord, use typedef coordinate_t
  coordinate_t coord = {.x = x, .y = y, .z = z};

  return coord;
}

coordinate_t scale_coordinate(coordinate_t coord, int factor) {
  coordinate_t scaled = coord;
  scaled.x *= factor;
  scaled.y *= factor;
  scaled.z *= factor;

  return scaled;
}
