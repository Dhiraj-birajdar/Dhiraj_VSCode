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
        int isupper = 1;
        for (int a = 1; a < r; a++)
        {
            for (int b = 0; b < c; b++)
            {
                if (a == b)
                {
                    break;
                }
                else if (a != b)
                {
                    if (arr[a][b] != 0)
                    {
                        isupper = 0;
                    }
                }
            }
        }

        // for (int x = 0; x < r; x++)
        // {
        //     for (int y = 0; y < c; y++)
        //     {
        //         if ( arr[x][y] < min )
        //         {
        //             min = arr[x][y];
        //         }
        //     }
        // }
        if (isupper == 1)
        {
            printf("matrix is upper triangular ");
        }
        else
        {
            printf("matrix is not upper triangular ");
        }
    }
    else
    {
        printf("matrix is not square");
    }
}