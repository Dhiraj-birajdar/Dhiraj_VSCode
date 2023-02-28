#include <stdio.h>
// int fact(int n)
// {
    
//     return factorial;
// }
int main()
{
    int n;
    printf("Enter the no : \n");
    scanf("%d",&n);
    int factorial=1;
    for (int i = 1; i <= n; i++)
    {
        factorial*=i;
    }
    printf("Factorial of %d is %d\n",n,factorial);
    return 0;
}