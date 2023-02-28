// b) Accept n values in array from user. Accept a value x from user and use sentinel linear search algorithm to check whether the number is present in the array or not and output the position if the number is present.
// Sentinel LINEAR SEARCH for integers
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
    if (index == -1)
        printf("\nelement not found");
    else
        printf("\n%d element found at %d position.", key, index + 1);
}
int sentinelsearch(int a[10], int n, int key)
{
    int i;
    a[n] = key;
    for(i=0;a[i] != key;i++);
    if (i == n)
        return -1;
    else
        return i;
}
