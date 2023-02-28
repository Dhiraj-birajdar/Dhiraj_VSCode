//menu driven program for even index sum and odd index sum
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s, n, ch, *a, i;
    printf("Enter no of elements : ");
    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));
    printf("\nEnter %d elements : ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do
    {
        printf("\n1. sum of even index\n2. sum of odd index\n3. exit\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            s = 0;
            for (i = 1; i < n; i++)
            {
                if (i % 2 == 0)
                    s += a[i];
            }
            printf("\nSum of even index no : %d\n", s);
            break;
        case 2:
            s = 0;
            for (i = 1; i < n; i++)
            {
                if (i % 2 != 0)
                    s += a[i];
            }
            printf("\nSum of odd index no : %d\n", s);
            break;
        case 3:
            printf("\n---Thanks!---");
            exit(1);
        default:
            printf("\nInvalid choice.\n");
        }
    } while (ch != 3);
    free(a);
    return 0;
}