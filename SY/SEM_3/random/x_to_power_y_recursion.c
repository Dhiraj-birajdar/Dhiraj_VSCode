#include <stdio.h>
int power_xy(int x, int a)
{
    if (a <= 1)
        return x;
    int p = x * power_xy(x, --a);
    return p;
}
void main()
{
    int x, y, s;
    printf("Enter x & y : ");
    scanf("%d%d", &x, &y);
    s = power_xy(x, y);
    printf("%d^%d = %d\n", x, y, s);
}
