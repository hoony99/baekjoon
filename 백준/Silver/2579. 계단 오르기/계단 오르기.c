#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)
#define MAX(a,b) a>b?a:b
int cnt = 0;
int dp[301];
int scoreArr[301];

int main() {
    int n, score;
    scanf("%d", &n); 
    for (int i = 1; i <= n; i++) {
        scanf("%d", &scoreArr[i]);
    }
    dp[0] = 0;
    dp[1] = scoreArr[1];
    dp[2] = scoreArr[1] + scoreArr[2];
    for (int i = 3; i <= n; i++) {
        dp[i] = scoreArr[i] + (MAX(dp[i - 2], scoreArr[i - 1] + dp[i - 3]));
    }

    printf("%d",dp[n]);
    return 0;
}