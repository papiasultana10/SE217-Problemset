#include <stdio.h>

#define INF 99999

struct Edge {
  int src, dest, weight;
};

void bellmanFord(int nodes, int edgesCount, struct Edge *edges, int start) {
  int dist[nodes];
  for(int i = 0; i < nodes; i++) {
    dist[i] = INF;
  }
  dist[start] = 0;
  for(int i = 1; i <= nodes - 1; i++) {
    for(int j = 0; j < edgesCount; j++) {
      int u = edges[j].src;
      int v = edges[j].dest;
      int w = edges[j].weight;
      if(dist[u] != INF && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }
  for(int j = 0; j < edgesCount; j++) {
    int u = edges[j].src;
    int v = edges[j].dest;
    int w = edges[j].weight;
    if(dist[u] != INF && dist[u] + w < dist[v]) {
      printf("Negative Cycle Detected!!\n");
      return;
    }
  }
  printf("Vertex Distance from Source:\n");
  for(int i = 0; i < nodes; i++) {
    printf("%d -> %d\n", i, dist[i]);
  }
}

int main() {
  int nodes = 5;
  int edgesCount = 7;
  struct Edge edges[] = {
    {0,1,6}, {0,2,7},
    {1,2,8}, {1,3,5},
    {1,4,-4},
    {2,3,-3},
    {3,4,9}
  };
  bellmanFord(nodes, edgesCount, edges, 0);
  return 0;
}
