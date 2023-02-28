#include <stdio.h>
int binary_search(int *a, int n, int no)
{
    int r = n - 1, l = 0, mid;
    while (l <= r)
    {
        mid = (r + l) / 2;
        if (a[mid] == no)
            return mid;
        else if (no > a[mid])
            l = mid + 1;
        else if (no < a[mid])
            r = mid - 1;
    }
    return -1;
}
int main()
{
    int i, n , f, in;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter %d elements in ascending order : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter no to search : ");
    scanf("%d", &f);
    in = binary_search(a, n, f);
    in == -1 ? printf("%d not found", f) : printf("%d found at position %d", f, in+1);
}

// without fn using loop
/*#include <stdio.h>
int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int n = 20, r = n - 1, l = 0, mid = (r + l) / 2, i, no = 16, in, f = 0;
    while (l <= r)
    {
        if (a[mid] == no)
        {
            in = mid;
            f = 1;
            break;
        }
        else if (no > a[mid])
            l = (mid) + 1;
        else if (no < a[mid])
            r = (mid)-1;
        mid = (r + l) / 2;
    }
    f == 1 ? printf("%d found at index %d", no, in) : printf("%d not found", no);
}*/