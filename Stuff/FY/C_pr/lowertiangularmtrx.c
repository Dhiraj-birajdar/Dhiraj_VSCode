#include <stdio.h>

void main()
{
    int r, c, arr[10][10], max, min;
    printf("Enter the row and column no : \n");
    scanf("%d%d", &r, &c);
    if (r == c)
    {
    printf("Enter values : ");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Matrix below \n");
    for (int k = 0; k < r; k++)
    {
        for (int l = 0; l < c; l++)
        {
            printf("%5.2d  ", arr[k][l]);
        }
        printf("\n");
    }
        int islower = 1;
        for (int a = 0; a < r; a++)
        {
            for (int b = 0; b < c; b++)
            {
                if (a < b && arr[a][b]!=0)
                {
                    islower=0;
                }
            }
        }
        if (islower == 1)
        {
            printf("matrix is lower triangular ");
        }
        else
        {
            printf("matrix is not lower triangular ");
        }
    }
    else
    {
        printf("matrix is not square");
    }
}