
void main()
{
    int i, j, n, s; 
    // int a[15] = {3, 4, 45, 1, 8, 7, 80, 2, 0, 9, 66, 16, 21, 3, 34};
    printf("Enter size of array : ");
    scanf("%d", &n);
    int f[n];
    printf("Enter %d elements : ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &f[i]);
    printf("Enter no to search : ");
    scanf("%d", &s);
    i = sno(f, s, n);
    printf("\nno %d is at a[%d]", s, i);
}

int sno(int *a, int x, int l)
{
    int i;
    for (i = 0; i < l; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
}