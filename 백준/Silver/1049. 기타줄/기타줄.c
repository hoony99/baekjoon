#pragma warning(disable:4996) 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main() {
	int arr[50][2] = { 0 };
	int num, brand, price = 0;
	scanf("%d %d", &num, &brand);

	for (int i = 0; i < brand; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	int minP = arr[0][0]; // 패키지 최소가격
	int minE = arr[0][1]; // 낱개 최소가격
	for (int i = 0; i < brand; i++) {
		if (arr[i][0] < minP)
			minP = arr[i][0];
		if (arr[i][1] < minE)
			minE = arr[i][1];
	}

	if ((6 * minE) < minP) {
		price += (num * minE);
		printf("%d", price);
		return 0;
	}
	else {
		while (num > 6) {
			price += minP;
			num -= 6;
		}
		price += (num * minE) < minP ? (num * minE) : minP;
		printf("%d", price);
	}

	return 0;
}