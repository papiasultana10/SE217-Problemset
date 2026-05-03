#include<stdio.h>

int sort(int *a, int size, int k){
  for(int i=0; i<k; i++){
    for(int j=0; j < size -1-i; j++){
      if(a[j]>a[j+1]){
        int temp =a[j];
        a[j]=a[j+1];
        a[j+1] = temp;
      }
    }
  }
  printf("%d th largest element is %d.", k, a[size-k]);
}

int main(){
  int a[6]={3,1,7,4,9,2};
  int k=2;
  sort(a,6,k);
  return 0;
}
