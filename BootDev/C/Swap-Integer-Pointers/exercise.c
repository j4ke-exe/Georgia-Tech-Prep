void swap_ints(int *a, int *b) {
  int c = *a; // c becomes *a (as *c)
  *a = *b; // *a becomes *b
  *b = c; // *b becomes *a, stored in *c
}
