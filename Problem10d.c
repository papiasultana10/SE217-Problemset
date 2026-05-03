#include <stdio.h>
#include <string.h>

int max(int a, int b) {
  if(a > b) return a;
  else return b;
}

int lcs(char s1[], char s2[]) {
  int m = strlen(s1);
  int n = strlen(s2);
  int dp[m+1][n+1];
  for(int i = 0; i <= m; i++) {
    for(int j = 0; j <= n; j++) {
      if(i == 0 || j == 0) {
        dp[i][j] = 0;
      }
      else if(s1[i-1] == s2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[m][n];
}

int main() {
  char s1[] = "PAPIA";
  char s2[] = "SULTANA";
  int result = lcs(s1, s2);
  printf("LCS length: %d\n", result);
  return 0;
}
