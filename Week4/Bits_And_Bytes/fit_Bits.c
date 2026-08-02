#include <stdio.h>

int fitsBits(int x, int n) {
  int shift = 32 + (~n + 1);
  return !(((x << shift) >> shift) ^ x);
}

int main() {
  int x, n;

  printf("Enter x: ");
  scanf("%d", &x);

  printf("Enter n: ");
  scanf("%d", &n);

  printf("%d\n", fitsBits(x, n));

  return 0;
}
