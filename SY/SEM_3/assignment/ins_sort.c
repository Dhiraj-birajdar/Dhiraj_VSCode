#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void display(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
}
int ins_sort(int *a, int n)
{
    int i, j, t;
    printf("\nBefore insertion sort : ");
    display(a, n);
    for (i = 1; i < n; i++)
    {
        t = a[i];
        for (j = i - 1; j >= 0 && a[j] > t; j--) //  5 4 3 2 1
            a[j + 1] = a[j];
        a[j + 1] = t;
    }
    printf("\nAfter insertion sort  : ");
    display(a, n);
}

int main()
{
    int a[] = {5, 4, 3, 2, 1, 9, 8, 7, 6, 0};
    // int a[10];
    // srand(time(0));
    // for (int i = 0; i < 10; i++)
    //     a[i] = rand() % 100;
    // int i,n,*a;
    // printf("Enter size of array : ");
    // scanf("%d",&n);
    // printf("\nEnter %d elements : ",n);
    // a=(int *)calloc(n,sizeof(int));
    // for(i=0;i<n;i++)
    //     scanf("%d",&a[i]);
    ins_sort(a, 10);
    return 0;
}