#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)


int main() {
    int n, k, cnt = 0, sum = 0;
    scanf("%d %d", &n, &k);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[n - i - 1]);
    }

    int idx = 0;
    while (1) {
        if (arr[idx] > k-sum) {
            idx++;
        }
        else {
            sum += arr[idx];
            cnt++;
        }


        if (sum >= k) {
            printf("%d", cnt);
            break;
        }
    }


    return 0;
}