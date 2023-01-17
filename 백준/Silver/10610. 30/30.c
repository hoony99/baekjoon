#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)

int main() {
    char arr[100001] = {0};
    int flag = 0, threeX = 0;
    scanf("%s", arr);
    for (int i = 0; i < strlen(arr); i++) {
        if (arr[i] == '0')
            flag = 1;
        threeX += (arr[i]-48);
    }
    if (flag == 0 || threeX % 3 != 0) {
        printf("-1");
        return 0;
    }
    char idx = '9';
    while (idx >= '0') {
        for (int i = 0; i < strlen(arr); i++) {
            if (arr[i] == idx) {
                printf("%c", arr[i]);
            }
        }
        idx--;
    }
    return 0;
}