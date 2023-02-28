#include <stdio.h>
int i=44;
int gcdiv(int a, int b)
{
    int  gcd = 1, n;
    if (a < b)
        n = a;
    else
        n = b;
    for (int i = n; i >= 2; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break;
        }
    }
    printf("\n i : %d\n",i);
    return gcd;
}
int main()
{
    int a, b, c;
    printf("Enter two no : ");
    scanf("%d%d", &a, &b);
    c = gcdiv(a, b);
    printf("Greatest common divisor : %d", c);
}