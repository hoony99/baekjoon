#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)
void fibonacci(int N)
{
    int last = 0, current = 1, result = 0; // last = 0 current = 1;
    for (int i = 0; i <= N; i++)
    {
        last = current;
        current = result;
        result = last + current;
    }
    printf("%d %d\n", last, current);
}
int main() {
    int n, testcase;
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) {
        scanf("%d", &testcase);
        fibonacci(testcase);
    }

    return 0;
}