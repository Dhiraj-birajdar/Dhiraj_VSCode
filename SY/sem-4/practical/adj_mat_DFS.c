#include<stdio.h>
int nov,a[20][20];
int visited[20];
void creatematrix()
{
	int i,j;
	printf("\nEnter no. of vertices: ");
	scanf("%d",&nov);

	//accept the matrix
	for(i=1;i<=nov;i++)
	{
		for(j=1;j<=nov;j++)
		{
			printf("\nIs there egde between V[%d] and V[%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}

}
void display(int a[20][20])  //print the matrix
{
	int i,j;
	for(i=1;i<=nov;i++)
	{
		for(j=1;j<=nov;j++)
			printf("\t%d",a[i][j]);
		printf("\n");
	}
}
void recdfs(int a[20][20],int nov,int ver)
{
	int i;
	visited[ver]=1;
	printf(" V%d",ver);
	for(i=1;i<=nov;i++)
	{
		
		if((a[ver][i]==1) && (visited[i]==0))
				recdfs(a,nov,i);
		}

}
int main()
{
	int ch,i;
	creatematrix();
	printf("\n\t***Adjacency Matrix****\n");
	display(a);
        
        printf("\nThe Depth First search Traversal(DFS) is:");
        recdfs(a,nov,1);
        return 0;
}