#include<stdio.h>

int palindrome(char *a, int left, int right){
  if(left >= right){
    return 1;
  }
  if(a[left]!=a[right]){
    return 0;
  }
  return palindrome(a, left + 1, right - 1);
}

int main(){
  int b;
  b= palindrome("racecar", 0, 6);
  if(b==1){
    printf("Palindrome!");
  }
  else{
    printf("Not Palindrome!");
  }
  return 0;
}
