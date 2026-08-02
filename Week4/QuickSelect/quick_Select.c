#include <stdio.h>

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

int main() {
  int n, k;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  int arr[n];

  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter value of K: ");
  scanf("%d", &k);

  if (k <= 0 || k > n) {
    printf("Invalid value of K\n");
    return 0;
  }

  quickSelect(arr, 0, n - 1, k - 1);

  printf("First %d smallest elements:\n", k);

  for (int i = 0; i < k; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}
