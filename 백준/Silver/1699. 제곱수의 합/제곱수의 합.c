#pragma warning(disable:4996) 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cnt = 0;

int main() {
	int n;
	int dp[100001] = {0};
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1 || dp[i] == 0)
				dp[i] = dp[i - j * j] + 1;
		}
	}
	printf("%d", dp[n]);
	return 0;
}