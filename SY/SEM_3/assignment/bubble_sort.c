#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubble_sort(int *a, int n)
{
    int i, pass, temp, oc = 0, ic = 0;
    printf("Before bubble sort : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    for (pass = 1; pass < n; pass++)
    {
        for (i = 0; i < n-pass; i++)
        {
            if (a[i] > a[i+1])
            {
               temp= a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
            }
            ++ic;
        }
        ++oc;
    }
    printf("\nAfter bubble sort : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\ncomparisons = %d\tpass = %d ", ic, oc);
}
int main()
{
    // int i,n,*a;
    // printf("Enter size of array : ");
    // scanf("%d",&n);
    // printf("\nEnter %d elements : ",n);
    // a=(int *)calloc(n,sizeof(int));
    // for(i=0;i<n;i++)
    // {
    //     scanf("%d",&a[i]);
    // }
    int a[5] ;
    srand(time(0));
    for(int i=0;i<5;i++)
        a[i]=rand()/100;
    bubble_sort(a, 5);
    return 0;
}


    // int a[] = {2,1,3,4,5};


