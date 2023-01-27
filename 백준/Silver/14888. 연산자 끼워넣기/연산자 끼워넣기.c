#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#pragma warning(disable : 4996)
int cnt, max = -100000000, min = 100000000; 
int plus, minus, mult, divi;
int arr[101];
void DFS(int plus, int minus, int mult, int divi, int x, int sum) {
    if (x == cnt - 1) {
        if (max < sum)
            max = sum;
        if (min > sum)
            min = sum;
    }
    if (plus > 0) {
        DFS(plus - 1, minus, mult, divi, x + 1, sum + arr[x + 1]);
    }
    if (minus > 0) {
        DFS(plus, minus - 1, mult, divi, x + 1, sum - arr[x + 1]);
    }
    if (mult > 0) {
        DFS(plus, minus, mult - 1, divi, x + 1, sum * arr[x + 1]);
    }
    if (divi > 0) {
        DFS(plus, minus, mult, divi - 1, x + 1, sum / arr[x + 1]);
    }
}

int main() {
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d %d %d", &plus, &minus, &mult, &divi);
    DFS(plus, minus, mult, divi, 0, arr[0]);

    printf("%d\n%d", max, min);

    return 0;
}