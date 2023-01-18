#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)
int arr[1001];
int dp[1001];
int main() {
    int t, max = 0;
    scanf("%d", &t); 
    for (int i = 1; i <= t; i++) {
        scanf("%d", &arr[i]);
        for (int j = 0; j < t; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j]+1) {
                dp[i] = dp[j] + 1;
                if (max < dp[i])
                    max = dp[i];
            }
        }
    }

    printf("%d", max);
    return 0;
}