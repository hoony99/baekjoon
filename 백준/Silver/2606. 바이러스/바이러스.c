#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#pragma warning(disable : 4996)
int m, n, cnt; 
int vertics[101][101];
int visited[101];
void DFS(int x) {
    for (int i = 1; i <= m; i++) {
        if (vertics[x][i] == 1 && visited[i] == 0) {
            cnt++;
            //printf("%d %d\n", x, cnt);
            visited[i] = 1;
            DFS(i);
        }
    }
    return;
}
void addGraph(int x, int y) {
    vertics[x][y] = 1;
    vertics[y][x] = 1;
}
int main() {
    int x, y;
    scanf("%d", &m); // 1~m번까지 컴퓨터 있음
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        addGraph(x, y);
    }/*
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", vertics[i][j]);
        }
        printf("\n");
    }*/
    DFS(1);
    printf("%d", cnt-1);
    return 0;
}