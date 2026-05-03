#include<stdio.h>

int sum(int* a, int size){
  int ans=0;
  for(int i=0; i<size; i++){
    ans+=a[i];
  }
  return ans;
}

int main(){
  int a[5]={25,41,5,42,6};
  int b=sum(a,5);
  printf("%d", b);
  return 0;
}
