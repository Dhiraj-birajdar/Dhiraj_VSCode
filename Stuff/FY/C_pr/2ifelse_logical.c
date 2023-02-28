#include <stdio.h>
int main()
{
    int a;
    int vip = 0;
    // vip=1;

    printf("enter the no\n");
    scanf("%d", &a);
    // if (a <= 70 && a >= 18)      for and use &&
    if ((a <= 70 && a >= 18) || (vip == 1)) //  for or use \\    for not use !
    {
        printf("you can drive\n");
    }
    else
    {
        printf("you cannot drive\n");
    }
    return 0;
}