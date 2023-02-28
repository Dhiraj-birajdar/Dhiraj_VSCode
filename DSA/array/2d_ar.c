#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    srand(time(0));
    int a[4][4], i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            a[i][j] = rand() % 100;
    }
    FILE *f;
    f = fopen("2d.txt", "a+");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            fprintf(f, "%.2d  ", a[i][j]);
        fprintf(f, "\n");
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%.2d  ", a[i][j]);
        printf("\n");
    }
    return 0;
}