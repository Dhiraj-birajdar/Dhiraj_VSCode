#include<stdio.h>
int nov,a[20][20];
void creatematrix()
{
	int i,j;
	printf("\nEnter no. of vertices: ");
	scanf("%d",&nov);

	//accept the matrix
	for(i=0;i<nov;i++)
	{
		for(j=0;j<nov;j++)
		{
			printf("\nIs there egede between V[%d] and V[%d]: ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}

}
void display(int a[20][20])  //print the matrix
{
	int i,j;
	for(i=0;i<nov;i++)
	{
		for(j=0;j<nov;j++)
			printf("\t%d",a[i][j]);
		printf("\n");
	}
}

void degree()
{
	int i,j,indegree,outdegree;

	printf("\nVertex\t     Indegree\t     Outdegree\t      Totaldegree \n");
	for(i=0;i<nov;i++)
	{
		indegree=0;
		outdegree=0; 
		for(j=0;j<nov;j++)
		{
			if(a[i][j]==1)
				outdegree+=1;
			if(a[j][i]==1)
				indegree+=1;
		}

		printf("\nV%d \t\t %d \t\t %d \t\t %d",i+1,indegree,outdegree,indegree+outdegree);
	}

}
int main()
{
	int ch;
	creatematrix();
	printf("\n\t***Adjacency Matrix****\n");
	display(a);
	degree();
    return 0;
}