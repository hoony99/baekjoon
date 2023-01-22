#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)
int n, m, cnt;
int change(int n, int m) {
    if (n == m) {
        return 1;
    }
    else if (n > m) {
        return 2;
    }

    if (m % 10 == 1) {
        m /= 10;
        cnt++;
        change(n, m);
    }
    else if(m % 2 == 0) {
        m /= 2;
        cnt++;
        change(n, m);
    }
    else {
        return 2;
    }
}
int main() {
    scanf("%d %d", &n, &m);

    if (change(n, m) == 1) {
        printf("%d", cnt + 1);
    }
    else {
        printf("-1");
    }

    // 1000 000 000
    return 0;
}