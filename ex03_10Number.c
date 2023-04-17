#include <stdio.h>

int main()
{
    int a, b, c, d, count=0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int sum;
    sum = a - b;
    while (1)
    {
        sum -= c;
        count++;
        if (sum <= 0 ) break;
        sum += d;
    }
    
    printf("%d", count);
    return 0;
}