#include <stdio.h>

int bitXor(int x, int y) { return ~((~(x & ~y)) & (~(~x & y))); }

int main() {
  int x, y;

  printf("Enter x: ");
  scanf("%d", &x);

  printf("Enter y: ");
  scanf("%d", &y);

  printf("Result = %d\n", bitXor(x, y));

  return 0;
}
