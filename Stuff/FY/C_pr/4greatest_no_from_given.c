#include <stdio.h>
int main()
{
    int a,b,c;
    printf("enter 3 nos with space:\n");
    scanf("%d%d%d",&a,&b,&c);
    if (a>b)
    {
        if (a>c)
        {
            printf("%d is greatest no \n",a);
        }
        
        
    }
    if (b>a)
    {
        if (b>c)
        {
            printf("%d is greatest no \n",b);
        }
        
        
    }
    if (c>a)
    {
        if (c>b)
        {
            printf("%d is greatest no \n",c);
        }
        
        
    }
    // else  (b>a||c||d)
    // {
    //     printf("%d is greatest no \n",b);
    // }
    // else  (c>a||b||d)
    // {
    //     printf("%d is greatest no \n",c);
    // }
    // else  (d>a||c||b)
    // {
    //     printf("%d is greatest no \n",d);
    // }
    return 0;
}