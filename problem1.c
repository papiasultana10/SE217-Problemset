#include<stdio.h>
void sort(int *a, int size){
if(size%2==0){
int n=(size/2);
for(int i=0; i<n; i++){
int min=i;
for(int j=i+1; j<size; j++){
if(a[min]>a[j]){
min=j;
}
}
if(min!=i){
int temp =a[i];
a[i]=a[min];
a[min]=temp;
}
}
printf("Median a[%d]: %d\n", n-1, a[n-1]);
}
else{
int n=(size/2);
for(int i=0; i<=n; i++){
int min=i;
for(int j=i+1; j<size; j++){
if(a[min]>a[j]){
min=j;
}
}
if(min!=i){
int temp =a[i];
a[i]=a[min];
a[min]=temp;
}
}
printf("Median a[%d]: %d", n, a[n]);
}
}
int main (){
int a[6]={45, 9, 33, 12, 5, 56};
sort(a,6);
int b[5]={6, 8, 13, 11, 2};
sort(b,5);
return 0;
}