#include<stdio.h>

int binarysearch(int *a, int left, int right, int key){
  if(left > right){
    return -1;
  }
  int mid =(left+right)/2;
  if(a[mid]==key){
    return mid;
  }
  else if(key<a[mid]){
    return binarysearch(a, left, mid - 1, key);
  }
  else{
    return binarysearch(a, mid + 1, right, key);
  }
}

int main(){
  int a[7]={1,2,3,4,5,6,7};
  int b= binarysearch(a,0,6,6);
  if(b!=-1){
    printf("found.\nIndex no: %d", b);
  }
  else{
    printf("not found.");
  }
  return 0;
}
