#include<stdio.h>
int main()
{
    int a, b, c, d, n, sum=1;
    int yi[101][101];
    scanf("%d", &n);
    for(a=0;a<=(n-1)/2;a++)
    {
        for(b=a;b<=n-a-1;b++)
            yi[b][n-a-1]=sum++;
        for(b=n-2-a;b>=a;b--)
            yi[n-a-1][b]=sum++;
        for(b=n-a-2;b>=a;b--)
            yi[b][a]=sum++;
        for(b=a+1;b<n-a-1;b++)
            yi[a][b]=sum++;
    }
    for(c=0;c<n;c++)
    {
        for(d=0;d<n;d++)
            printf("%3d", yi[c][d]);
        printf("\n");
    }
}    