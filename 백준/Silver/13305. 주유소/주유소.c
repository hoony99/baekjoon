#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)


int main() {
    int n, roadSum = 0, priceSum = 0, min = 10000;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n-1); // 도로 길이
    int* arr2 = (int*)malloc(sizeof(int) * n); // 도시별 리터당 가격
    for (int i = 0; i < n-1; i++) { // 도로 길이
        scanf("%d", &arr[i]);
        roadSum += arr[i];
    }
    for (int i = 0; i < n; i++) { // 도시별 리터당 가격
        scanf("%d", &arr2[i]);
        if (min > arr2[i] && i != n-1) {
            min = arr2[i];
        }
    }
    for (int i = 0; i < n-1; i++) {
        if (i == 0) {
            if (arr2[0] <= arr2[1]) {
                if (arr2[0] == min) {
                    priceSum += roadSum * arr2[0];
                    break;
                }
                else {
                    priceSum += (arr[0] + arr[1]) * arr2[0];
                    roadSum -= (arr[0] + arr[1]);
                }

            }
            else {
                priceSum += (arr[0]) * arr2[0];
                roadSum -= (arr[0]);
            }
        }
        else {
            if (arr2[i] == min) {
                priceSum += (roadSum * min);
                break;
            }
            else {
                priceSum += arr[i] * arr2[i];
                roadSum -= (arr[i]);
            }
        }
    }    

    printf("%d", priceSum);
    return 0;
}