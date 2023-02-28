#include<stdio.h>
void display(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
}
void selection(int *a,int n)
{
    int i,j,t,m;
    printf("Before selection sort : ");
    display(a,n);
    for(i=0;i<n;i++)
    {
        m=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[m])
                m=j;
        if(m!=i)
        {
            t=a[i];
            a[i]=a[m];
            a[m]=t;
        }
    }
    printf("\nAfter selection sort : ");
    display(a,n);
}
void main()
{
    int a[]={5,4,3,2,1},n=5;
    selection(a,n);
}