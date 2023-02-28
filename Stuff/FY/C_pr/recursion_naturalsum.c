#include <stdio.h>
int nsum (int n);
int main()
{
    int a;
    printf("Enter the no:\n");
    scanf("%d",&a);
    printf("Sum of %d natural nos is %d\n",a,nsum(a));
        
    return 0;
}

int nsum (int n)
{
    if(n<=1)
    {
        return 1;
    }
    else
    {
        return n+nsum(n-1);
    }
}