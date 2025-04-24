#include<stdio.h>
#include<string.h>

int main() {
  char s[] = "When the zombies arrive, quickly fax Judge Pat Alphabet";
  char p[] = "poolloop";  
  
  // Conceal s with '*'
  for (int i = 0; i < strlen(s); i++) {
    s[i] = '*';
  }
  printf("%s\n", s);

  // Replace first half with #
  for (int i = 0; i < strlen(p); i++) {
    p[i/2] = '#';
  }
  printf("%s", p);
}
