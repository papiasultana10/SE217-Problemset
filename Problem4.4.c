#include<stdio.h>

double power(double base, int exp){
  if(exp==0){
    return 1;
  }
  double k=1.00;
  for(int i=1; i<=exp; i++){
    k=k*base;
  }
  return k;
}

int main(){
  double p;
  int q;
  printf("Enter a num: ");
  scanf("%lf", &p);
  printf("Enter a expotent: ");
  scanf("%d", &q);
  double value=power(p,q);
  printf("Value: %.3lf\n", value);
  return 0;
}
