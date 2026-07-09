#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void generateRandom(int a[], int s) {
  int i;
  for (i = 0; i < s; i++) {
    a[i] = rand() % s + 1;
  }
}

void generateAscending(int a[], int s) {
  int i;
  for (i = 0; i < s; i++) {
    a[i] = i;
  }
}

void generateDescending(int a[], int s) {
  int i;
  for (i = 0; i < s; i++) {
    a[i] = s - i;
  }
}

void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void merge(int a[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[n1], R[n2];

  int i, j, k;

  for (i = 0; i < n1; i++)
    L[i] = a[left + i];

  for (j = 0; j < n2; j++)
    R[j] = a[mid + 1 + j];

  i = 0;
  j = 0;
  k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

void mergeSortHelper(int a[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSortHelper(a, left, mid);
    mergeSortHelper(a, mid + 1, right);

    merge(a, left, mid, right);
  }
}

void mergeSort(int a[], int n) { mergeSortHelper(a, 0, n - 1); }

void print(int a[], int s) {
  int i;
  for (i = 0; i < s; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {

  struct timeval te;

  int size = 8000;
  int step = 4000;
  int i;
  int choice;

  printf("Choose Input Type\n");
  printf("1. Random\n");
  printf("2. Ascending\n");
  printf("3. Descending\n");
  printf("Enter Choice: ");
  scanf("%d", &choice);

  for (i = 0; i < 8; i++) {

    int a[size];

    if (choice == 1)
      generateRandom(a, size);
    else if (choice == 2)
      generateAscending(a, size);
    else if (choice == 3)
      generateDescending(a, size);
    else {
      printf("Invalid Choice\n");
      return 0;
    }

    gettimeofday(&te, NULL);
    long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;

    mergeSort(a, size);

    gettimeofday(&te, NULL);
    long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

    printf("%lld\n", end - start);

    size += step;
  }

  printf("\n");

  return 0;
}
