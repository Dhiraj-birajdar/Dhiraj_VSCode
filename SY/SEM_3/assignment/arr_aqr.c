// accept array and store squar of arr display
#include <stdio.h>

int main()
{
    int *a, n, i, *s;
    printf("Enter no of elements : ");
    scanf("%d", &n);
    a = s = (int *)calloc(n, sizeof(int));
    printf("\nEnter %d elements : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        s[i]=a[i]*a[i];
    }
    printf("\nelements : ", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nsquare elements : ", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", s[i]);
    }

    return 0;
}