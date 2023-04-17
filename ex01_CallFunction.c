#include <stdio.h>

int count = 0;

int f(int x, int y) {
    count++;  // 每次呼叫 f 函數時增加計數器 count 的值
    if (x < 0) {
        return f(y, -x);
    } else if (x > y) {
        return f(y, x);
    } else if (x == 0) {
        return y;
    } else {
        return f(y % x, x);
    }
}

int main() {
    int x, y, gcd;
    scanf("%d %d", &x, &y);
    gcd = f(x, y);
    printf("%d\n%d", count, gcd);
    return 0;
}
