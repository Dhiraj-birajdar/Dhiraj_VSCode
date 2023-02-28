#include <stdio.h>
int sentinelsearch(int *a, int n, int key);
main()
{
    int a[10], n, i, key, index;
    printf("How many element do you want to enter in array : ");
    scanf("%d", &n);
    printf("\n Enter %d elements : ",n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the element to search : ");
    scanf("%d", &key);
    index = sentinelsearch(a, n, key);
    if (index == n)
        printf("\nelement %d not found",key);
    else
        printf("\n%d element found at %d position.", key, index + 1);
}
int sentinelsearch(int a[10], int n, int key)
{
    int i;
    a[n] = key;
    for(i=0;a[i] != key;i++);
    return i;
}