#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable : 4996)
int Queue[10000];
int cnt, front, rear;
void EnQueue(int data) {
    Queue[front++] = data;
}
int DeQueue() {
    return Queue[rear++];
}
int main() {
    int n, num, idx, important, flag;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        front = 0, rear = 0, cnt = 0;

        scanf("%d %d", &num, &idx);
        for (int j = 0; j < num; j++) {
            scanf("%d", &important);
            EnQueue(important);
        }

        while (1) {
            flag = 0;
            for (int j = rear; j < num + rear; j++) { // 탈출조건 검사
                if (Queue[rear] >= Queue[j])
                    flag++;
            }
            if (flag == num) { // 탈출 가능
                int tmp = DeQueue();
                cnt++;
                num--;
                if (idx+1 == rear) {
                    printf("%d\n", cnt);
                    break;
                }
            }
            else { // 탈출 불가능
                if (idx == rear)
                    idx = front;

                int tmp = DeQueue();
                EnQueue(tmp);
            }
        }
    }
    return 0;

}
