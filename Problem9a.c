#include <stdio.h>
#include <limits.h>

#define V 6

int findMin(int dist[], int visited[]) {
  int min = INT_MAX;
  int index = -1;
  for(int i = 0; i < V; i++) {
    if(visited[i] == 0 && dist[i] < min) {
      min = dist[i];
      index = i;
    }
  }
  return index;
}

void dijkstra(int graph[V][V], int src) {
  int dist[V];
  int visited[V];
  for(int i = 0; i < V; i++) {
    dist[i] = INT_MAX;
    visited[i] = 0;
  }
  dist[src] = 0;
  for(int i = 0; i < V - 1; i++) {
    int u = findMin(dist, visited);
    visited[u] = 1;
    for(int v = 0; v < V; v++) {
      if(graph[u][v] != 0 && visited[v] == 0) {
        if(dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
          dist[v] = dist[u] + graph[u][v];
        }
      }
    }
  }
  printf("Vertex Distance\n");
  for(int i = 0; i < V; i++) {
    printf("%d\t%d\n", i, dist[i]);
  }
}

int main() {
  int graph[V][V] = {
    {0, 4, 2, 0, 0, 0},
    {4, 0, 1, 5, 0, 0},
    {2, 1, 0, 8, 10, 0},
    {0, 5, 8, 0, 2, 6},
    {0, 0, 10, 2, 0, 3},
    {0, 0, 0, 6, 3, 0}
  };
  dijkstra(graph, 0);
  return 0;
}
