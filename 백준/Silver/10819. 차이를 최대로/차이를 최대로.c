#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)

int arr[9];
int visited[8];
int rep[9];
int N, result;
void DFS(int depth) {
    if (depth == N) {
        int total = 0;
        for (int i = 0; i < N - 1; i++) {
            int sum = abs(rep[i] - rep[i + 1]);
            total += sum;
        }
        result = fmax(total, result);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            rep[depth] = arr[i];
            DFS(depth + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    DFS(0);
    printf("%d", result);
    return 0;
}