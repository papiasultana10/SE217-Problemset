#include<stdio.h>

long long factorial(int n){
  long long fact = 1;
  if(n==0){
    return fact;
  }
  else{
    for(int i=1; i <= n; i++){
      fact = fact * i;
    }
    return fact;
  }
}

int main(){
  int n;
  printf("Enter a number to find factorial: ");
  scanf("%d", &n);
  long long value=factorial(n);
  printf("value: %lld\n", value);
  return 0;
}
