// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// void display(int *a, int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//         printf("%d  ", a[i]);
// }
// void merge(int *a, int low, int mid, int high)
// {
//     int i, j, k, b[20];
//     i = low;
//     j = mid + 1;
//     k = 0;
//     while (i <= mid && j <= high)
//     {
//         if (a[i] <= a[j])
//             b[k++] = a[i++];
//         else
//             b[k++] = a[j++];
//     }
//     while (i <= mid)
//         b[k++] = a[i++];
//     while (j <= high)
//         b[k++] = a[j++];
//     for (j = low, k = 0; j <= high; j++, k++)
//         a[j] = b[k];
// }
// void mergesort(int *a, int low, int high)
// {
//     int mid;
//     if (low < high)
//     {
//         mid = (low + high) / 2;
//         mergesort(a, low, mid);
//         mergesort(a, mid + 1, high);
//         merge(a, low, mid, high);
//     }
// }
// void main()
// {
//     int a[20], i, n=10;
//     // printf("how many no : ");
//     // scanf("%d", &n);
//     // printf("\nEnter unsorted no : ");
//     // for (i = 0; i < n; i++)
//         // scanf("%d", &a[i]);
//     srand(time(0));
//     for(i=0;i<n;i++)
//         a[i]=rand()%100;
//     printf("The unsorted list  : ");
//     display(a,n);
//     mergesort(a, 0, n - 1);
//     printf("\nThe sorted list is : ");
//     display(a, n);
// }









#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void display(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
}
void merge(int *a,int l,int m,int h)
{
    int i,j,k,b[20];
    i=l;
    j=m+1;
    k=0;
    while(i<=m&&j<=h)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=m)
        b[k++]=a[i++];
    while(j<=h)
        b[k++]=a[j++];
    for(j=l,k=0;j<=h;j++,k++)
        a[j]=b[k];
}
void mergesort(int *a,int l,int h)
{
    int m;
    if(l<h)
    {
        m=(l+h)/2;
        mergesort(a,m+1,h);
        mergesort(a,l,m);
        merge(a,l,m,h);
    }
}
void main()
{
    int n=10,a[n],i;
    srand(time(0));
    for(i=0;i<n;i++)
        a[i]=rand()%100;
    printf("unsort : ");
    display(a,n);
    mergesort(a,0,n-1);
    printf("\nsort   : ");
    display(a,n);
}