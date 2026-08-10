#include <stdio.h>

#define MAX 1000

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void maxHeapifyUp(int i) {
  while (i > 0) {
    int parent = (i - 1) / 2;

    if (maxHeap[parent] >= maxHeap[i])
      break;

    swap(&maxHeap[parent], &maxHeap[i]);
    i = parent;
  }
}

void minHeapifyUp(int i) {
  while (i > 0) {
    int parent = (i - 1) / 2;

    if (minHeap[parent] <= minHeap[i])
      break;

    swap(&minHeap[parent], &minHeap[i]);
    i = parent;
  }
}

void maxHeapifyDown(int i) {
  while (1) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < maxSize && maxHeap[left] > maxHeap[largest])
      largest = left;

    if (right < maxSize && maxHeap[right] > maxHeap[largest])
      largest = right;

    if (largest == i)
      break;

    swap(&maxHeap[i], &maxHeap[largest]);
    i = largest;
  }
}

void minHeapifyDown(int i) {
  while (1) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < minSize && minHeap[left] < minHeap[smallest])
      smallest = left;

    if (right < minSize && minHeap[right] < minHeap[smallest])
      smallest = right;

    if (smallest == i)
      break;

    swap(&minHeap[i], &minHeap[smallest]);
    i = smallest;
  }
}

void insertMax(int num) {
  maxHeap[maxSize] = num;
  maxSize++;
  maxHeapifyUp(maxSize - 1);
}

void insertMin(int num) {
  minHeap[minSize] = num;
  minSize++;
  minHeapifyUp(minSize - 1);
}

int removeMax() {
  int root = maxHeap[0];

  maxHeap[0] = maxHeap[maxSize - 1];
  maxSize--;

  if (maxSize > 0)
    maxHeapifyDown(0);

  return root;
}

int removeMin() {
  int root = minHeap[0];

  minHeap[0] = minHeap[minSize - 1];
  minSize--;

  if (minSize > 0)
    minHeapifyDown(0);

  return root;
}

void insert(int num) {
  if (maxSize == 0 || num <= maxHeap[0])
    insertMax(num);
  else
    insertMin(num);

  if (maxSize > minSize + 1)
    insertMin(removeMax());

  else if (minSize > maxSize + 1)
    insertMax(removeMin());
}

float getMedian() {
  if (maxSize == minSize)
    return (maxHeap[0] + minHeap[0]) / 2.0;

  if (maxSize > minSize)
    return maxHeap[0];

  return minHeap[0];
}

int main() {
  int n, num;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &num);
    insert(num);
    printf("%.1f\n", getMedian());
  }

  return 0;
}
