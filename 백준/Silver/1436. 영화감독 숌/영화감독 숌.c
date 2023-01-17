#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)

int numDigit(int n) {
    int cnt = 0;
    while (1) {
        n /= 10;
        cnt++;
        if (!n)
            break;
    }
    return cnt;
}
int searchThree(int n) {
    while (n > 0) {
        int tmp = n;
        if (tmp % 10 == 6) {
            tmp /= 10;
            if (tmp % 10 == 6) {
                tmp /= 10;
                if (tmp % 10 == 6) {
                    return 1;
                }
            }

        }
        n /= 10;
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int num = 666;
    while (1) {
        if (searchThree(num) == 1) {
            cnt++;
        }
        if (cnt == n)
            break;

        num++;
    }
    printf("%d",num);
    return 0;
}