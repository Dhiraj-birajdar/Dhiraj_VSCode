#include <stdio.h>
#include "dhiraj.h"

void main()
{
    int f, n;
    printf("Enter no : ");
    scanf("%d", &n);
    f = fact(n);
    
    printf("Factorial of %d is %d.", n, f);
    printf("\nfibonachi %d",fib(n));
    printf("\nsum = %d",((n*(n+1))/2));
}