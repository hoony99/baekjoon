#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)
long long dp[101];

long long test(int n) {
    if (n == 1 || n == 2 || n == 3) {
        return 1;
    }
    else if (n == 4 || n == 5) {
        return 2;
    }
    else if (dp[n] != 0)
        return dp[n];
    else
        return dp[n] = test(n - 1) + test(n - 5);
}

int main() {
    int cnt;
    int n, m;
    scanf("%d", &cnt);
    
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &n);

        printf("%lld\n", test(n));
    }
    return 0;
}
