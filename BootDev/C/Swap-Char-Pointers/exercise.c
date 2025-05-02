void swap_strings(char **a, char **b) {
  char *c = *a;
  *a = *b;
  *b = c;
}
