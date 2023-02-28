#include <stdio.h>

void main()
{
    int r,c,arr[10][10],occ,sum;
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
    // =================================================
    printf("Matrix below \n");
    for (int k = 0; k < r; k++)
    {
        for (int l = 0; l < c; l++)
        {
            printf("%5.1d  ",arr[k][l]);
        }
        printf("\n");
    }
    // =================================================
    printf("enter the no to check occurence : ");
    scanf("%d",&occ);
    sum=0;
    for (int a = 0; a < r; a++)
    {
        for (int b = 0; b < c; b++)
        {
            if ( arr[a][b] == occ )
            {
                sum = sum+1;
            }
        }
    }
    printf("occurence of %d is %d times",occ,sum);
}