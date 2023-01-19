#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable : 4996)
#define max 1000
int vertics[max + 1][max + 1];
int DFSvisited[max + 1];
int BFSvisited[max + 1];
int Queue[max + 1];
int front = 0, rear = 0;

void AddEdge(int start, int goal);
void DFS(int s, int n);
void BFS(int s, int n);

void EnQueue(int data);
int DeQueue();
int isEmpty();
int main() {
    int n, m, s, a, b;
    scanf("%d %d %d", &n, &m, &s);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        AddEdge(a, b);
    }

    printf("%d ", s);
    DFSvisited[s] = 1;
    DFS(s, n); // 시작위치 + 최대개수
    
    printf("\n");
    
    printf("%d ", s);
    BFSvisited[s] = 1;
    BFS(s, n);

    return 0;

}
void AddEdge(int start, int goal) {
    vertics[start][goal] = 1;
    vertics[goal][start] = 1;
}
void DFS(int s, int n) {
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (DFSvisited[i] == 1)
            flag++;
    }
    if (flag == n) // 종료조건
        return;

    for (int i = 1; i <= n; i++) {
        if (vertics[s][i] == 1 && DFSvisited[i] == 0) {
            printf("%d ", i);
            DFSvisited[i] = 1;
            DFS(i, n);
        }
    }
}
void BFS(int s, int n) {
    EnQueue(s);
    BFSvisited[s] = 1;

    while (!isEmpty()) {
        int x = DeQueue();
        for (int i = 1; i <= n; i++) {
            if (vertics[x][i] == 1 && BFSvisited[i] == 0) {
                printf("%d ", i);
                BFSvisited[i] = 1;
                EnQueue(i);
            }
        }
    }

}
int isEmpty() {
    if (rear == front) {
        return 1;
    }
    else
        return 0;
}
void EnQueue(int data) {
    Queue[++rear] = data;
}
int DeQueue() {
    return Queue[++front];
}