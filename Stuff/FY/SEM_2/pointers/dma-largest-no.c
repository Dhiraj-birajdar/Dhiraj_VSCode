#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    float *data;
    printf("Enter total no : ");
    scanf("%d", &n);
    data = (float *)calloc(n, sizeof(float));
    if (data == NULL)
    {
        printf("Error memory not allocated.\n");
        exit(0);
        // return 1;
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter no %d : \n", i + 1);
        scanf("%f", data + i);
    }
    for (i = 1; i < n; i++)
    {
        if (*data < *(data + i))
        {
            *data = *(data + i);
        }
    }
    printf("Largest no is %.2f\n", *data);

    return 0;
}

