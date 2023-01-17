#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)


int main() {
    int n, sum = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            sum += arr[j];
        }
    }
    printf("%d", sum);
    return 0;
}