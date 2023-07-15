#pragma warning(disable:4996) 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int checkPrime(int n) { // 소수면 1, 아니면 0
	for (int i = 2; i <= n/2; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
void getGold(int n) {
	int a = n / 2;
	int b = n / 2;
	while (1) {
		if (checkPrime(a) == 1 && checkPrime(b) == 1) {
			printf("%d %d", a, b);
			break;
		}
		else {
			a--;
			b++;
		}
	}
}
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		getGold(m);
		printf("\n");
	}
	return 0;
}