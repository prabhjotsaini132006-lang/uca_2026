#include <stdio.h>

int isPower2(int x) { return !!x & !(x & (x + ~0)) & !(x >> 31); }

int main() {
  int x;

  scanf("%d", &x);

  printf("%d\n", isPower2(x));

  return 0;
}
