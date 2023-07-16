#pragma warning(disable:4996) 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int gcd(int x, int y) { // 최소공배수
	int max = x;
	while (1) {
		if (max % x == 0 && max % y == 0) {
			return max;
		}
		max+=x;
	}
}
int lcm(int x, int y) { // 최대공약수
	int min = x > y ? y : x;
	while (1) {
		if (x % min == 0 && y % min == 0) {
			return min;
		}
		min--;
	}
}
int main() {
	int n, M, N, x, y, cnt = 0, flag = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		int limit = gcd(M, N);
		int j;
		for (j = x; j <= limit; j+=M) {
			int tmp = (j % N == 0) ? N : j % N;
			if (tmp == y) {
				printf("%d\n", j);
				break;
			}
		}
		if (j > limit) {
			printf("-1\n");
		}

	}
	return 0;
}