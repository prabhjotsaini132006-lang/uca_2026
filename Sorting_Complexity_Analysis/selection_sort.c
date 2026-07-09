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

void selectionSort(int a[], int n) {
  int i, j, min;

  for (i = 0; i < n - 1; i++) {
    min = i;

    for (j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }

    if (min != i) {
      swap(a, i, min);
    }
  }
}

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

    selectionSort(a, size);

    gettimeofday(&te, NULL);
    long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

    printf("%lld\n", end - start);

    size += step;
  }

  printf("\n");

  return 0;
}
