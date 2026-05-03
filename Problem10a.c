#include<stdio.h>

int maxVal(int a,int b){
  return (a>b)?a:b;
}

int knapsack01(int wt[],int val[],int n,int W){
  int dp[n+1][W+1];
  for(int i=0;i<=n;i++){
    for(int w=0;w<=W;w++){
      if(i==0||w==0){
        dp[i][w]=0;
      }
      else if(wt[i-1]<=w){
        dp[i][w]=maxVal(dp[i-1][w],dp[i-1][w-wt[i-1]]+val[i-1]);
      }
      else{
        dp[i][w]=dp[i-1][w];
      }
    }
  }
  return dp[n][W];
}

int main(){
  int wt[]={2,3,4,5,9};
  int val[]={3,4,8,8,10};
  int n=5,W=10;
  printf("Maximum value: %d\n",knapsack01(wt,val,n,W));
  return 0;
}
