#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)

int main() {
    int n;
    scanf("%d", &n);

    int dp[1000001] = { 0, };

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            if (dp[i] > dp[i / 2] + 1)
                dp[i] = dp[i / 2] + 1;
        }
        if (i % 3 == 0) {
            if (dp[i] > dp[i / 3] + 1)
                dp[i] = dp[i / 3] + 1;
        }
    }
    printf("%d", dp[n]);
    return 0;
}