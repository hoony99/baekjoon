#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)


int main() {
    int n, result = 0, min, cur;
    scanf("%d", &n);
    int arr[100000];

    for (int i = 0; i < n-1; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n-1; i++) {
        scanf("%d", &cur);
        if (i == 0 || min > cur)
            min = cur;
        result += min * arr[i];
    }    
    printf("%d", result);
    return 0;
}