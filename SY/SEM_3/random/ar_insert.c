#include<stdio.h>
void insert(int *p,int *n,int e,int l)
{
    int i,t;
    for ( i = l; i < *n+1; i++)
    {
        t=p[i];
        p[i]=e;
        e=t;
    }
    (*n)++;
}

void main()
{
    int *a,i,n,e,l;
    printf("Enter no of elements : ");
    scanf("%d",&n);
    a=(int *)calloc(n,sizeof(int));
    printf("%d",sizeof(a));
    for ( i = 0; i < n; i++)
    {
        printf("\nEnter %d element : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nEnter element to be inserted : ");
    scanf("%d",&e);
    printf("\nEnter the index location : ");
    scanf("%d",&l);
    printf("\nBefore insert : ");
    for ( i = 0; i < n; i++)
        printf("%d ",a[i]);
    insert(a,&n,e,l);
    // n++;
    printf("\nAfter insert : ");
    for ( i = 0; i < n; i++)
        printf("%d ",a[i]);
}