#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable : 4996)
char Stack[10000];
int front;
void push(char data) {
    Stack[front++] = data;
}
void pop() {
    Stack[--front];
}
int main() {
    int n, cnt;
    char arr[51];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        front = 0;
        cnt = 0;
        for (int j = 0; j < strlen(arr); j++) {
            if (arr[j] == '(') {
                push(arr[j]);
                cnt++;
            }
            else if (arr[j] == ')') {
                if (front > 0 && Stack[front - 1] == '(') {
                    pop();
                }
                cnt--;
            }
        }
        if (cnt == 0 && front == 0) // cnt == 0 -> 여는괄호 닫는괄호 갯수 세기 , front == 0
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;

}
