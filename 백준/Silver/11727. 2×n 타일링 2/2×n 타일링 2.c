#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)
int dp[1001];
int tile(int n) {
    if (n == 1) {
        dp[n] = 1;
        return 1;
    }
    if (n == 2) {
        dp[n] = 3;
        return 3;
    }
    if (dp[n] != 0) return dp[n];
    return dp[n] = (tile(n - 1) + 2 * tile(n - 2))%10007;
}
int main() {
    int n;
    scanf("%d", &n); 
    printf("%d", tile(n));

    return 0;
}