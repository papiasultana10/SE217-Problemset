#include<stdio.h>

int digit(int n){
  if(n==0){
    return 1;
  }
  int s=0;
  int k=n;
  while(k>0){
    k=k/10;
    s++;
  }
  return s;
}

int main(){
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  int m=digit(n);
  printf("Digit: %d\n", m);
  return 0;
}
