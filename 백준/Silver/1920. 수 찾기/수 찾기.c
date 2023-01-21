#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable : 4996)
int arrN[100001];
int arrM[100001];

int binary_search(int* arr,int target, int start, int end) {
    if (start > end)
        return 0;
    int mid = (start + end) / 2;
    if (arr[mid] == target)
        return 1;
    else if (arr[mid] > target) {
        binary_search(arr, target, start, mid - 1);
    }
    else
        binary_search(arr, target, mid + 1, end);
}
int cmp(const void* a, const void* b) {
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrN[i]);
    }
    qsort(arrN, n, sizeof(int), cmp);



    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arrM[i]);
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", binary_search(arrN, arrM[i], 0, n - 1));
    }

    return 0;
}
