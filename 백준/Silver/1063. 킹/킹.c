#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable : 4996)
int KING[1][2] = {0};
int STONE[1][2] = {0};
int main() {
    char king[3], stone[3];
    int n;
    scanf("%s %s %d", king, stone, &n);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if (king[0]-'A' == i && king[1]-'0' == j+1) {
                KING[0][0] = i;
                KING[0][1] = j;
            }
            if (stone[0]-'A' == i && stone[1]-'0' == j+1) {
                STONE[0][0] = i;
                STONE[0][1] = j;
            }
        }
    }    


    char order[10];
    for (int i = 0; i < n; i++) { // 0~7 범위 내에서 움직임
        scanf("%s", order);
        if (strcmp(order, "R") == 0) { // 한 칸 오른쪽으로
            if (KING[0][0] + 1 > 7) { // 가로축이 7 밖으로 벗어남
                continue;
            }
            else if (KING[0][0] + 1 == STONE[0][0] && KING[0][1] == STONE[0][1] && STONE[0][0] + 1 > 7) {
                continue;
            }
            else if (KING[0][0] + 1 == STONE[0][0] && KING[0][1] == STONE[0][1]) {
                KING[0][0]++;
                STONE[0][0]++;
            }
            else {
                KING[0][0]++;
            }
        }
        else if (strcmp(order, "L") == 0) { // 한 칸 왼쪽으로
            if (KING[0][0] - 1 < 0) { // 가로축이 7 밖으로 벗어남
                continue;
            }
            else if (KING[0][0] - 1 == STONE[0][0] && KING[0][1] == STONE[0][1] && STONE[0][0] - 1 < 0) { // 돌이랑 겹치는데 돌이 범위를 벗어남
                continue;
            }
            else if (KING[0][0] - 1 == STONE[0][0] && KING[0][1] == STONE[0][1]) {
                KING[0][0]--;
                STONE[0][0]--;
            }
            else {
                KING[0][0]--;
            }
        }
        else if (strcmp(order, "B") == 0) { // 한 칸 아래로
            if (KING[0][1] - 1 < 0) { // 세로축이 7 밖으로 벗어남
                continue;
            }
            else if (KING[0][1] - 1 == STONE[0][1] && KING[0][0] == STONE[0][0] && STONE[0][1] - 1 < 0) { // 돌이랑 겹치는데 돌이 범위를 벗어남
                continue;
            }
            else if (KING[0][1] - 1 == STONE[0][1] && KING[0][0] == STONE[0][0]) {
                KING[0][1]--;
                STONE[0][1]--;
            }
            else {
                KING[0][1]--;
            }
        }
        else if (strcmp(order, "T") == 0) { // 한 칸 위로
            if (KING[0][1] + 1 > 7) { // 가로축이 7 밖으로 벗어남
                continue;
            }
            else if (KING[0][1] + 1 == STONE[0][1] && KING[0][0] == STONE[0][0] && STONE[0][1] + 1 > 7) {
                continue;
            }
            else if (KING[0][1] + 1 == STONE[0][1] && KING[0][0] == STONE[0][0]) {
                KING[0][1]++;
                STONE[0][1]++;
            }
            else {
                KING[0][1]++;
            }
        }
        else if (strcmp(order, "RT") == 0) { // 오른쪽 위 대각선으로
            if (KING[0][1] + 1 > 7 || KING[0][0] + 1 > 7) {
                continue;
            }
            else if ((KING[0][1] + 1 == STONE[0][1] && KING[0][0] + 1 == STONE[0][0]) && (STONE[0][1] + 1 > 7 || STONE[0][0] + 1 > 7)) {
                continue;
            }

            else if (KING[0][1] + 1 == STONE[0][1] && KING[0][0] + 1 == STONE[0][0]) {
                KING[0][0]++;
                KING[0][1]++;
                STONE[0][0]++;
                STONE[0][1]++;
            }
            else {
                KING[0][0]++;
                KING[0][1]++;
            }
        }
        else if (strcmp(order, "LT") == 0) { // 왼쪽 위 대각선으로
            if (KING[0][1] + 1 > 7 || KING[0][0] - 1 < 0) { // 가로축 세로축 중 하나라도 안되면 안됨
                continue;
            }
            else if ((KING[0][1] + 1 == STONE[0][1] && KING[0][0] - 1 == STONE[0][0]) && (STONE[0][1] + 1 > 7 || STONE[0][0] - 1 < 0)) {
                continue;
            }

            else if (KING[0][1] + 1 == STONE[0][1] && KING[0][0] - 1 == STONE[0][0]) {
                KING[0][0]--;
                STONE[0][0]--;
                KING[0][1]++;
                STONE[0][1]++;
            }
            else {
                KING[0][0]--;
                KING[0][1]++;
            }
        }
        else if (strcmp(order, "RB") == 0) { // 오른쪽 아래 대각선으로
            if (KING[0][1] - 1 < 0 || KING[0][0] + 1 > 7) {
                continue;
            }
            else if ((KING[0][1] - 1 == STONE[0][1] && KING[0][0] + 1 == STONE[0][0]) && (STONE[0][1] - 1 < 0 || STONE[0][0] + 1 > 7)) {
                continue;
            }

            else if (KING[0][1] - 1 == STONE[0][1] && KING[0][0] + 1 == STONE[0][0]) {
                KING[0][0]++;
                KING[0][1]--;
                STONE[0][0]++;
                STONE[0][1]--;
            }
            else {
                KING[0][0]++;
                KING[0][1]--;
            }
        }
        else if (strcmp(order, "LB") == 0) { // 왼쪽 아래 대각선으로
            if (KING[0][1] - 1 < 0 || KING[0][0] - 1 < 0) {
                continue;
            }
            else if ((KING[0][1] - 1 == STONE[0][1] && KING[0][0] - 1 == STONE[0][0]) && (STONE[0][1] - 1 < 0 || STONE[0][0] - 1 < 0)) {
                continue;
            }

            else if (KING[0][1] - 1 == STONE[0][1] && KING[0][0] - 1 == STONE[0][0]) {
                KING[0][0]--;
                KING[0][1]--;
                STONE[0][0]--;
                STONE[0][1]--;
            }
            else {
                KING[0][0]--;
                KING[0][1]--;
            }
        }
    }

    printf("%c%d\n", KING[0][0] + 'A', KING[0][1] + 1);
    printf("%c%d\n", STONE[0][0] + 'A', STONE[0][1] + 1);

    return 0;
}
