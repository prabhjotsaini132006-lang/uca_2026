#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t size) {
  void *temp = malloc(size);

  memcpy(temp, a, size);
  memcpy(a, b, size);
  memcpy(b, temp, size);

  free(temp);
}

void heapify(void *arr, int n, int i, size_t size,
             int (*cmp)(const void *, const void *)) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n &&
      cmp((char *)arr + left * size, (char *)arr + largest * size) > 0) {
    largest = left;
  }

  if (right < n &&
      cmp((char *)arr + right * size, (char *)arr + largest * size) > 0) {
    largest = right;
  }

  if (largest != i) {
    swap((char *)arr + i * size, (char *)arr + largest * size, size);

    heapify(arr, n, largest, size, cmp);
  }
}

void heap_sort(void *arr, int n, size_t size,
               int (*cmp)(const void *, const void *)) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i, size, cmp);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(arr, (char *)arr + i * size, size);

    heapify(arr, i, 0, size, cmp);
  }
}

int intComparator(const void *a, const void *b) {
  int x = *(const int *)a;
  int y = *(const int *)b;

  return x - y;
}

int main() {
  int arr[] = {1, 2, 3, 4, 9, 8, 10, 6, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before sorting:\n");

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  heap_sort(arr, n, sizeof(arr[0]), intComparator);

  printf("After sorting:\n");

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}
