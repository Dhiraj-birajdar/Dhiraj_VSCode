//Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency matrix. Display the adjacency matrix
#include<stdio.h>
#include<stdlib.h>

int a[10][10];

int main()
{
    int v, i, j;
    printf("How many vertices? : ");
    scanf("%d", &v);
    for(i = 0; i < v; i++)
    {
        for(j = 0; j < v; j++)
        {
            printf("is there edge between v[%d] and v[%d] (enter 0 for no, 1 for yes) : ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nAdjacency matrix : \n\n");
    for(i = 0; i < v; i++)
    {
        for(j = 0; j < v; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nAdjacency List : \n\n");
    for(i = 0; i < v; i++)
    {
        printf("%d -> ", i+1);
        for(j = 0; j < v; j++)
        {
            if(a[i][j] == 1)
                printf("%d -> ", j+1);
        }
        printf("NULL");
        printf("\n");
    }
    
}