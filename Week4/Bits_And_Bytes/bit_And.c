#include <stdio.h>

int bitAnd(int x, int y) { return ~(~x | ~y); }

int main() {
  int x, y;

  printf("Enter the value of x: ");
  scanf("%d", &x);

  printf("Enter the value of y: ");
  scanf("%d", &y);

  printf("Result = %d\n", bitAnd(x, y));

  return 0;
}
