#include <stdio.h>

int main()
{
    int sum = 0, r, c, arr[10][10];

    printf("Enter rows and columns : ");
    scanf("%d%d", &r, &c);

    if (r == c)
    {
        printf("Enter the %d values : ", r * c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        printf("matrix is\n");
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                printf("%3.1d |", arr[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i == j)
                {
                    sum = sum + arr[i][j];
                }
            }
        }
        printf("sum of diagonal of above matrix is %d", sum);
    }
    else
    {
        printf("No diagonal element exists. (not square matrix)\n");
    }

    return 0;
}