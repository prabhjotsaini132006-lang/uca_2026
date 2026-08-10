#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void generateRandomArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = rand() % n + 1;
}

void generateAscendingArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = i + 1;
}

void generateDescendingArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = n - i;
}

void sink(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    sink(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    sink(arr, n, i);

  for (int i = n - 1; i > 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    sink(arr, i, 0);
  }
}

int main() {

  struct timeval te;

  int size = 8000;
  int step = 4000;
  int choice;

  printf("Choose Input Type\n");
  printf("1. Random\n");
  printf("2. Ascending\n");
  printf("3. Descending\n");
  printf("Enter Choice: ");
  scanf("%d", &choice);

  printf("\nSize\tTime(ms)\n");

  for (int i = 0; i < 8; i++) {

    int arr[size];

    if (choice == 1)
      generateRandomArray(arr, size);
    else if (choice == 2)
      generateAscendingArray(arr, size);
    else if (choice == 3)
      generateDescendingArray(arr, size);
    else {
      printf("Invalid Choice\n");
      return 0;
    }

    gettimeofday(&te, NULL);
    long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;

    heapSort(arr, size);

    gettimeofday(&te, NULL);
    long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

    printf("%d\t%lld\n", size, end - start);

    size += step;
  }

  return 0;
}
