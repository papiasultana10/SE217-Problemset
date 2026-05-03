#include<stdio.h>

int maxarray(int *a, int size){
  int max=a[0];
  for(int i=1; i<size; i++){
    if(a[i]>max){
      max =a[i];
    }
  }
  return max;
}

int main(){
  int a[5]={28,6,43,21,7};
  int b= maxarray(a,5);
  printf("Maximun element: %d\n", b);
  return 0;
}
