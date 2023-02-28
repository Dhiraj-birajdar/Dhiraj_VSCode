#include <stdio.h>
int main()
{
    int n;
    printf("Enter no");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    // for (int i = n; i >= 1; i--)
    {
        for (int space = 1; space <= (n - i); space++)
        {
            printf(" ");
        }
        for (int star = 1; star <= (2 * i - 1); star++)
        {
            printf("*");
        }
        printf("\n");
    }

    // for (int i = 2; i <= n; i++)
    // for (int i = n-1; i >= 1; i--)
    // {
    //     for (int space = 1; space <= (n - i); space++)
    //     {
    //         printf(" ");
    //     }
    //     for (int star = 1; star <= (2*i-1); star++)
    //     {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    return 0;
}