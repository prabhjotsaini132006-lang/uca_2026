#include <stdio.h>

#define MAX 1000

struct Village {
  int population;
  int clinics;
};

struct Village heap[MAX];
int size = 0;

double getLoad(struct Village v) { return (double)v.population / v.clinics; }

void swap(struct Village *a, struct Village *b) {
  struct Village temp = *a;
  *a = *b;
  *b = temp;
}

void heapifyUp(int index) {
  while (index > 0) {
    int parent = (index - 1) / 2;

    if (getLoad(heap[parent]) >= getLoad(heap[index]))
      break;

    swap(&heap[parent], &heap[index]);
    index = parent;
  }
}

void heapifyDown(int index) {
  while (1) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && getLoad(heap[left]) > getLoad(heap[largest]))
      largest = left;

    if (right < size && getLoad(heap[right]) > getLoad(heap[largest]))
      largest = right;

    if (largest == index)
      break;

    swap(&heap[index], &heap[largest]);
    index = largest;
  }
}

void insert(struct Village v) {
  heap[size] = v;
  size++;
  heapifyUp(size - 1);
}

struct Village removeMax() {
  struct Village root = heap[0];

  heap[0] = heap[size - 1];
  size--;

  if (size > 0)
    heapifyDown(0);

  return root;
}

int main() {
  int n, k;
  int population[MAX];

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d", &population[i]);

  scanf("%d", &k);

  for (int i = 0; i < n; i++) {
    struct Village v;

    v.population = population[i];
    v.clinics = 1;

    insert(v);
  }

  for (int i = n; i < k; i++) {
    struct Village v = removeMax();

    v.clinics++;

    insert(v);
  }

  printf("%.2f\n", getLoad(heap[0]));

  return 0;
}
