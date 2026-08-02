#include <stdio.h>

int sign(int x) { return (x >> 31) | (!!x); }

int main() {
  int x;
  scanf("%d", &x);

  printf("%d\n", sign(x));

  return 0;
}
