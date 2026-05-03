#include <stdio.h>

int swap = 0;

int partition(int *a, int low, int high) {
  int pivot = a[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (a[j] < pivot) {
      i++;
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      swap++;
    }
  }
  int temp = a[i + 1];
  a[i + 1] = a[high];
  a[high] = temp;
  swap++;
  return i + 1;
}

void sort(int *a, int low, int high) {
  if (low < high) {
    int pi = partition(a, low, high);
    sort(a, low, pi - 1);
    sort(a, pi + 1, high);
  }
}

int main() {
  int a[] = {23,45,12,67,34,89,2,90,11,56};
  int n = sizeof(a) / sizeof(a[0]);
  sort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\nTotal swaps: %d\n", swap);
  return 0;
}
