#include <stdio.h>
void display(int *a,int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
}
void bubble_sort(int *a, int n)
{
    int i, p, temp, f,pc = 0, cc = 0;
    printf("Before bubble sort : ");
    display(a,n);
    // for (p = 0; p < n-1; p++)
    for (p = 1; p < n; p++)
    {
        f=0;
        // for (i = 0;i<(n-p-1) ; i++)
        for (i = 0;i<n-p ; i++)
        {
            if (a[i] > a[i+1])
            {
               temp= a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
                f=1;
            }
            ++cc;
        }
        ++pc;
        if(!f)break;
    }
    printf("\nAfter bubble sort  : ");
    display(a,n);
    printf("\ncomparisons = %d    pass = %d ", cc, pc);
}
int main()
{
    int a[] = {5,4,3,2,1};
    // int a[] = {1,2,3,4,5};
    // int a[] = {2,1,3,4,5};
    // int i,n,*a;
    // printf("Enter size of array : ");
    // scanf("%d",&n);
    // printf("\nEnter %d elements : ",n);
    // a=(int *)calloc(n,sizeof(int));
    // for(i=0;i<n;i++)
    //     scanf("%d",&a[i]);
    bubble_sort(a, 5);
    return 0;
}