#include <stdio.h>

int main()
{
    int n = 16, arr[10];
    int temp = n;
    for (int i = 1; i <= 10; i++)
    {
        arr[i] = i * n;
    }

    for (int d = 1; d <= 10; d++)
    {
        printf("%d*%d=%d\n", d, n, arr[d]);
    }
    return 0;
}