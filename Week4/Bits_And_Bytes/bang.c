#include <stdio.h>

int bang(int x) { return ((x | (~x + 1)) >> 31) + 1; }

int main() {
  int x;

  scanf("%d", &x);

  printf("%d\n", bang(x));

  return 0;
}
