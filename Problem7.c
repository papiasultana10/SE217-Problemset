#include <stdio.h>

typedef struct {
  int weight;
  int value;
} Item;

void swap(Item *a, Item *b) {
  Item temp = *a;
  *a = *b;
  *b = temp;
}

double getRatio(Item item) {
  return (double)item.value / item.weight;
}

void sortItems(Item items[], int n) {
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if(getRatio(items[j]) < getRatio(items[j + 1])) {
        swap(&items[j], &items[j + 1]);
      }
    }
  }
}

double fractional_knapsack(Item items[], int n, int capacity) {
  sortItems(items, n);
  double totalValue = 0.0;
  for(int i = 0; i < n; i++) {
    if(capacity >= items[i].weight) {
      totalValue += items[i].value;
      capacity -= items[i].weight;
    }
    else {
      double fraction = (double)capacity / items[i].weight;
      totalValue += items[i].value * fraction;
      break;
    }
  }
  return totalValue;
}

int main() {
  int n, capacity;
  printf("Enter number of items: ");
  scanf("%d", &n);
  Item items[n];
  printf("Enter weights:\n");
  for(int i = 0; i < n; i++) {
    scanf("%d", &items[i].weight);
  }
  printf("Enter values:\n");
  for(int i = 0; i < n; i++) {
    scanf("%d", &items[i].value);
  }
  printf("Enter capacity: ");
  scanf("%d", &capacity);
  double result = fractional_knapsack(items, n, capacity);
  printf("Maximum value: %.2lf\n", result);
  return 0;
}
