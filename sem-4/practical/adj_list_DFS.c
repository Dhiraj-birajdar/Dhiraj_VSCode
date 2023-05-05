#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int data;
  struct NODE *next;
};
typedef struct NODE node;
node *list[10];
int nov,visited[20];
node *getnodenum(int vno)
{
   node *temp;
   temp=(node*) malloc(sizeof(node));
   temp->data=vno;
   temp->next=NULL;
   return temp;
}
void display(node *list[10])
{
  int i;
  node *ptr;
  for(i=1;i<=nov;i++)
  {
	  printf("V%d  ",i);
	  for(ptr=list[i];ptr!=NULL;ptr=ptr->next)
		  printf("%d->",ptr->data);
	  printf("NULL");
	  printf("\n");
  }

}
void creatadjacencylist()
{
	int i,j;
	char ch;
	node *temp,*last;
	for(i=1;i<=nov;i++)
		list[i]=NULL;
	for(i=1;i<=nov;i++)
	{
		for(j=1;j<=nov;j++)
		{
			printf("\nIs there edge between V[%d] and V[%d] (Choose (y/n): ",i,j);
			scanf(" %c",&ch);
			if(ch=='Y' || ch=='y')
			{
				temp=getnodenum(j);
				if(list[i]==NULL)
					list[i]=temp;
				else
				{
					for(last=list[i];last->next!=NULL;last=last->next);
					last->next=temp;
				}
			}
		}
	}
}
void recdfs(node *list[10],int nov,int ver)
{
        int i;
        node *ptr;
        visited[ver]=1;
        printf(" V%d",ver);
        //for(i=1;i<=nov;i++)
        for(ptr=list[ver];ptr!=NULL;ptr=ptr->next)
        {

            if((visited[ptr->data]==0))
                recdfs(list,nov,ptr->data);
        }

}

int main()
{
  int i,j,a[20][20];
 
  printf("\nEnter no. of vertices: ");
  scanf("%d",&nov);

  creatadjacencylist();
  printf("\n******Adjacency List*******\n");
  display(list);
  printf("\nDFS Sequence: ");
   recdfs(list,nov,1);
   return 0;
}