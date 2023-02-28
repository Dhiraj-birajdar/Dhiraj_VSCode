// sum of largest pair int array
#include <stdio.h>
int larg_pair_sum(int *a, int n)
{
    int i, m1 = 0, m2 = 0;
    for (i = 1; i < n; i++)
    {
        if (a[i] > a[m1])
            m1 = i;
    }
    for (i = 1; i < n && a[i] < a[m1]; i++)
    {
        if (a[i] > a[m2])
            m2 = i;
    }
    return a[m1] + a[m2];
}

int main()
{
    int *a, n, i, s;
    printf("Enter no of elements : ");
    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));
    printf("\nEnter %d elements : ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    s = larg_pair_sum(a, n);
    printf("\nSum of largest no pair is %d", s);
    return 0;
}