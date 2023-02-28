#include <stdio.h>
int main()
{
    int a;
    printf("enter the no\n");
    scanf("%d", &a);
    /**can be writtn in 1 line=  
    **  (a%2==0)?printf("%d is even\n", a):printf("%d is odd", a);  
    **  (condition) ?=if execution :=else execution ;
    */
    if (a % 2 == 0)
    {
        printf("%d is even\n", a);
    }
    else
    {
        printf("%d is odd", a);
    }
    return 0;
}