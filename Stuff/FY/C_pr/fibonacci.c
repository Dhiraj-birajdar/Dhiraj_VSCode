#include<stdio.h>
int fib(int n);
int main()
{
    int a;
    printf("Enter the no:\n");
    scanf("%d",&a);
    printf("Fibonacci no of %d is %d\n",a,fib(a));
}

int fib(int n)
{
    if (n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}