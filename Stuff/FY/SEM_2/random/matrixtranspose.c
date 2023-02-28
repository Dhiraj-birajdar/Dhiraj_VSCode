#include <stdio.h>
void main()
{
    int r,c,i,j;
    printf("enter rows and colums of matrix (r c) : ");
    scanf("%d%d",&r,&c);
    int m[r][c];
    printf("Enter %d elements of (%d * %d) matrix : ",r*c,r,c);
    for ( i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
        {
            scanf("%d",&m[i][j]);
            printf("%2.d | ",m[i][j]);
        }
        printf("\n");
    }
    printf("Matrix A :\n");
    printf("\nTranspose of Matrix A : \n");
    for ( j = 0; j < c; j++)
    {
        for ( i = 0; i < r; i++)
        {
            printf("%2.d |",m[i][j]);
        }
        printf("\n");
    }
    
    //----------------------------------------------------------------------
    // int m1[10][10],i,j,r,c;
    // printf("enter rows and colums of matrix (r c)");
    // scanf("%d%d",&r,&c);
    // printf("Enter elements of (3 * 3) matrix.");
    // for ( i = 0; i < r; i++)
    // {
    //     for ( j = 0; j < c; j++)
    //     {
    //         scanf("%d",&m1[i][j]);
    //     }
    // }
    // printf("Matrix A :\n");
    // for ( i = 0; i < r; i++)
    // {
    //     for ( j = 0; j < c; j++)
    //     {
    //         printf("%3.3d | ",m1[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\nTranspose of Matrix A :\n");
    // for ( j = 0; j < c; j++)
    // {
    //     for ( i = 0; i < r; i++)
    //     {
    //         printf("%3.3d |",m1[i][j]);
    //     }
    //     printf("\n");
    // }
}