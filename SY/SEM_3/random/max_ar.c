#include <stdio.h>
int maxno(int *a, int l);
void main()
{
    int i, j, a[15] = {3, 4, 45, 12, 8, 7, 80, 2, 5, 9, 66, 16, 21, 3, 34};
    // int *p = &a[10];
    // printf("%d  %d  ", p[4], p[5]);
    i=maxno(a,15);
    // printf("max no is %d at a[%d]",a[i],i);
}


int maxno(int *a, int l)
{
    int mx = 0,mn = 0, i;
    for (i = 1; i < l; i++)
    {
        if (a[i] > a[mx])
        {
            mx = i;
        }
        if (a[i] < a[mn])
        {
            mn = i;
        }
    }
    printf("\nMax : %d \tMin : %d",a[mx],a[mn]);
    printf("\nNo between %d   and   %d : \n",a[mn],a[mx]);
    for ( i = a[mn]+1; i < a[mx]; i++)
    {
        printf(" %d",i);
    }
    
    return mx;
}