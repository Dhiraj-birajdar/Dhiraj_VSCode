#include<stdio.h>
#include<stdlib.h>

#define MAX 20

struct n
 {
   int data;
   struct n *link;
 };

typedef struct n NODE;
NODE *h[20];
struct queue
{
  int front,rear;
  int Q[MAX];
};
typedef struct queue QUEUE;
QUEUE *q;

void initqueue()
{
  int i;
  for(i=0;i<MAX;i++)
    q->Q[i]=0;
  q->rear=-1;
  q->front=-1;
  printf("\nQueue created");
}
void add(int data)
{

   q->Q[++q->rear]=data;
}


int delet()
{

   return(q->Q[++q->front]);
}
int isempty()
{
  if (q->rear==q->front)
    return 1;
  else
   return 0;
}

void accept(int n,int a[MAX][MAX])
{
	int i,j;
	for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
       {
	 printf("\n Enter a[%d][%d] : ",i+1,j+1);
	 scanf("%d",&a[i][j]);
       }
    }
}
void display(int n,int a[MAX][MAX])
{
	int i,j;
	for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
       {
	 printf("\t %d ",a[i][j]);
       }
      printf("\n");
    }
}
void bfs(int n,int a[MAX][MAX])
{
  int i,j,v[10]={0};
  printf("\n \t BFS seq. :\n ");
   i=1;
   add(i);
    v[i-1]=1;
    while(isempty()!=1)
      {
	i=delet();
	for(j=0;j<n;j++)
	  {
	    if(a[i-1][j]==1 && v[j]==0)
	      {
		add(j+1);
		v[j]=1;
	      }
	  }
	printf("\t V%d ",i);
      }
}
NODE *getnode(int j)
 {
   NODE * temp;
   temp=(NODE *)malloc(sizeof(NODE));
   temp->data=j;
   temp->link=NULL;
   return(temp);
 }

NODE *findlast(NODE *h)
 {
   NODE *ptr;
   for(ptr=h;ptr->link!=NULL;ptr=ptr->link);
   return(ptr);
 }

void displaylist(NODE *h[10],int n)
 {
   NODE *ptr;
   int i;
   for(i=0;i<n;i++)
    {
      printf("\n V%d ",i+1);
      ptr=h[i];
      if(ptr==NULL)
       printf(" NULL");
      while(ptr!=NULL)
       {
	 printf(" -> %d",ptr->data);
	 ptr=ptr->link;
       }
      printf("\n");
    }
 }
void adjmat(int n,int a[MAX][MAX])
{
  NODE *ptr,*temp;
  int i,j;
   for(i=0;i<n;i++)
    h[i]=NULL;
   for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
       {
	 if(a[i][j]!=0)
	  {
	    temp=getnode(j+1);
	    if(h[i]==NULL)
	     h[i]=temp;
	    else
	     {
	       ptr=findlast(h[i]);
	       ptr->link=temp;
	     }
	  }
       }
    }
   printf("\n The Adjacency list looks like ... \n");
   displaylist(h,n);

 }


void main()
 {
   int ver,matric[MAX][MAX];
	printf("\n\t\t\t Enter the no. of vertex ");
	scanf("%d",&ver);
	accept(ver,matric);
	printf("\nAdjacency matrix:- \n");
	display(ver,matric);
	adjmat(ver,matric);
	bfs(ver,matric);
}

