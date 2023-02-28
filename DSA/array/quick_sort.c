#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void display(int *a,int n);
void quick_sort(int *a,int low,int high);
int partition(int *a,int low,int high);
void swap(int *a,int *b);
void main()
{
    int n=10,i,a[n];
    srand(time(0));
    for(i=0;i<n;i++)
        a[i]=rand()%100;
    printf("%-18s","Before q sort : ");
    display(a,n);
    quick_sort(a,0,n-1);
    printf("\n%-18s","After q sort  :");
    display(a,n);

}
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void display(int *a,int n)
{
    int i;
    for ( i = 0; i < n; i++)
        printf("%d  ",a[i]);
}
void quick_sort(int *a,int low,int high)
{
    int loc;
    if(low<high)
    {
        loc=partition(a,low,high);
        quick_sort(a,low,loc-1);
        quick_sort(a,loc+1,high);
    }
}
int partition(int *a,int low,int high)
{
    int p=a[low],start=low,end=high;
    while (start < end)
    {
        for(;a[start]<=p;start++);
        for(;a[end]>p;end--);
        if(start<end)
            swap(&a[start],&a[end]);
    }
    swap(&a[low],&a[end]);
    return end;
}