// p10-write a program to accept n integers & store them dynamically display them in reverse order.
#include <stdio.h>
void main()
{
    int *ints, n, i;
    int max = 0;
    printf("\nEnter the no of integers : ");
    scanf("%d", &n);
    ints = (int *)malloc(n * sizeof(int));
    printf("\nEnter %d integers:\n",n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ints[i]);
    }
    printf("\nEntered integers are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", ints[i]);
    }
    printf("\nReversed integers are:\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d  ", ints[i]);
    }
}