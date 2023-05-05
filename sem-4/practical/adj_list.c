#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int data;
  struct NODE *next;
};
typedef struct NODE node;
node *list[10];
int nov;
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
  for(i=0;i<nov;i++)
  {
	  printf("V%d  ",i+1);
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
	for(i=0;i<nov;i++)
		list[i]=NULL;
	for(i=0;i<nov;i++)
	{
		for(j=0;j<nov;j++)
		{
			printf("\nIs there edge between V[%d] and V[%d] (Choose (y/n): ",i+1,j+1);
			scanf(" %c",&ch);
			if(ch=='Y' || ch=='y')
			{
				temp=getnodenum(j+1);
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

	//display(list);
}

int main()
{
  int i,j,a[20][20];
 
  printf("\nEnter no. of vertices: ");
  scanf("%d",&nov);

  creatadjacencylist();
  printf("\n******Adjacency List*******\n");
  display(list);
  return 0;
}