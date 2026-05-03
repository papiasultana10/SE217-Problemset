#include<stdio.h>

void sort(int *a, int p, int *b, int q, int *c){
  for(int i=0; i<p; i++){
    c[i]=a[i];
  }
  int k=0;
  for(int j = p; j < (p+q); j++){
    c[j]=b[k];
    k++;
  }
  for(int j=1; j<(p+q); j++){
    int key =c[j];
    int i=j-1;
    while( i>=0 && c[i]>key){
      c[i+1]=c[i];
      i--;
    }
    c[i+1]=key;
  }
  printf("Sorted Array: ");
  for(int i=0; i<(p+q); i++){
    if(i==(p+q)-1)
      printf("%d", c[i]);
    else
      printf("%d, ", c[i]);
  }
}

int main(){
  int a[5]={8,3,15,1,6};
  int b[3]={20,11,2};
  int c[8];
  sort(a, 5, b, 3, c);
  return 0;
}
