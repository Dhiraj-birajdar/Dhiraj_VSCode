// Adjacency matrix
#include<stdio.h>
int main()
{
    int n=20, adj[n][n], nov, i, j;
    printf("Enter no of vertices : ");
    scanf("%d",&nov);
    for(i=0;i<nov;i++)
    {
        for(j=0;j<nov;j++)
        {
            printf("\nis there edge bet V[%d] and V[%d] (enter 1 for yes 0 for no) : ",i+1,j+1);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nAdjacency matrix\n");
    for(i=0;i<nov;i++)
    {
        for(j=0;j<nov;j++)
            printf("%d  ",adj[i][j]);
        printf("\n");
    }
}