#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr, i, j);
    }
  }

  swap(arr, i + 1, high);

  return i + 1;
}

void quickSelect(int arr[], int low, int high, int k) {
  if (low < high) {
    int pivotIndex = partition(arr, low, high);

    if (pivotIndex == k)
      return;
    else if (pivotIndex > k)
      quickSelect(arr, low, pivotIndex - 1, k);
    else
      quickSelect(arr, pivotIndex + 1, high, k);
  }
}

void generateRandom(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100000;
  }
}

int main() {
  srand(time(NULL));

  int k = 100;

  printf("Size\tTime(ms)\n");

  for (int n = 10000; n <= 100000; n += 10000) {
    int *arr = (int *)malloc(n * sizeof(int));

    generateRandom(arr, n);

    struct timeval start, end;

    gettimeofday(&start, NULL);

    quickSelect(arr, 0, n - 1, k - 1);

    gettimeofday(&end, NULL);

    double timeTaken = (end.tv_sec - start.tv_sec) * 1000.0 +
                       (end.tv_usec - start.tv_usec) / 1000.0;

    printf("%d\t%.3f\n", n, timeTaken);

    free(arr);
  }

  return 0;
}
