#include <stdio.h>

void sort(int *a,int b,int c,int d){
  int e=c-b+1;
  int f=d-c;
  int g[e],h[f];
  for(int i=0;i<e;i++){
    g[i]=a[b+i];
  }
  for(int j=0;j<f;j++){
    h[j]=a[j+c+1];
  }
  int i=0,j=0,k=b;
  while(i<e&&j<f){
    if(g[i]<=h[j]){
      a[k]=g[i];
      i++;
    }
    else{
      a[k]=h[j];
      j++;
    }
    k++;
  }
  while(i<e){
    a[k]=g[i];
    i++;
    k++;
  }
  while(j<f){
    a[k]=h[j];
    j++;
    k++;
  }
}

void partition(int *a,int b,int c){
  if(b<c){
    int d=b+((c-b)/2);
    partition(a,b,d);
    partition(a,d+1,c);
    sort(a,b,d,c);
  }
}

int main(){
  int a[8]={45,12,78,3,56,89,1,23};
  partition(a,0,7);
  for(int i=0;i<=7;i++){
    printf(" %d",a[i]);
  }
  return 0;
}
