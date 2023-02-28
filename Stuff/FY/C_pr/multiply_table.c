#include <stdio.h>
int main()
{
    int a, i;
    printf("enter the no:");
    scanf("%d", &a);

    for (i = 1; i<=10; i++)                      //  multiplication table
    {
        printf("%d*%d=%d\n", a, i, a * i);
        // if (a * i == a * 10)                 // not required cause of  i<=10
        // {
        //     break;
        // }
    }

    // for (i = 10; i; i--)                      // multiplication table in reverse order
    // {
    //     printf("%d*%d=%d\n", a, i, a * i);  
    //     // if (a * i == a)                    // not required cause of i decreases to 0
    //     // {
    //     //     break;
    //     // }
    // }

    return 0;
}