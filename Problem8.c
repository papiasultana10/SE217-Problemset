#include<stdio.h>

void prims(int grap[][5], int v){
  int selected[v];
  for(int i=0;i<v;i++){
    selected[i]=0;
  }
  int edges=1;
  selected[0]=1;
  printf("Edge : Weight\n");
  while(edges < v){
    int min = 99999;
    int x=0, y=0;
    for(int i=0; i<v; i++){
      if(selected[i]==1){
        for(int j=0; j<v; j++){
          if(selected[j]==0 && grap[i][j]!=0){
            if(grap[i][j] < min){
              min = grap[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d-%d : %d\n", x, y, min);
    selected[y] = 1;
    edges++;
  }
}

int main (){
  int v = 5;
  int grap[5][5] = {
    {0, 4, 0, 0, 6},
    {4, 0, 5, 0, 2},
    {0, 5, 0, 7, 3},
    {0, 0, 7, 0, 8},
    {6, 2, 3, 8, 0}
  };
  prims(grap, v);
  return 0;
}
