#include <stdio.h>
int main()
{
    int a;
    printf("enter the no\n");
    scanf("%d", &a);
    
    // if ((a <= 70 && a >= 18) || (vip == 1)) //  for or use \\    for not use !
    if (a==1)
    {
        printf("your no is 1\n");
    }
    else if(a==2){
        printf("your no is 2\n");
    }
    else if(a==2){
        printf("your no is 3\n");
    }
    else
    {
        printf("your no is not 1,2 or 3!\n");
    }
    return 0;
}