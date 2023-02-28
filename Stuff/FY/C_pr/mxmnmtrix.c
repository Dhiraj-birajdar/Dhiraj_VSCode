#include <stdio.h>

void main()
{
    int r,c,arr[10][10],max,min;
    printf("Enter the row and column no : \n");
    scanf("%d%d",&r,&c);
    printf("Enter values : ");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Matrix below \n");
    for (int k = 0; k < r; k++)
    {
        for (int l = 0; l < c; l++)
        {
            printf("%5.2d  ",arr[k][l]);
        }
        printf("\n");
    }
    max = arr[0][0];
    min = arr[0][0];
    for (int a = 0; a < r; a++)
    {
        for (int b = 0; b < c; b++)
        {
            if ( arr[a][b] > max )
            {
                max = arr[a][b];
            }
        }
    }
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            if ( arr[x][y] < min )
            {
                min = arr[x][y];
            }
        }
    }
    printf("Max = %d\nMin = %d",max,min);
}