#include <stdio.h>

void main()
{
    int r,arr[10],occ,sum;
    printf("Enter the row and column no : \n");
    scanf("%d",&r);
    printf("Enter values : ");
    for (int i = 0; i < r; i++)
    {
        // for (int j = 0; j < c; j++)
        // {
            scanf("%d",&arr[i]);
        // }
    }
    // =================================================
    printf("Matrix below \n");
    for (int k = 0; k < r; k++)
    {
        // for (int l = 0; l < c; l++)
        // {
            printf("%5.1d  ",arr[k]);
        // }
        // printf("\n");
    }
    // =================================================
    printf("enter the no to check occurence : ");
    scanf("%d",&occ);
    sum=0;
    for (int a = 0; a < r; a++)
    {
        // for (int b = 0; b < c; b++)
        // {
            if ( arr[a]== occ )
            {
                sum = a+1;
            }
        // }
    }
    printf("occurence of %d is at %d position",occ,sum);
}