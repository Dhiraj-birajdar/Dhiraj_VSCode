#include <stdio.h>

int nov, a[20][20];

void creatematrix()
{
    int i, j;
    printf("\nEnter no. of vertices: ");
    scanf("%d", &nov);

    // accept the matrix
    for (i = 0; i < nov; i++)
    {
        for (j = 0; j < nov; j++)
        {
            printf("\nIs there egde between V[%d] and V[%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int a[20][20]) // print the matrix
{
    int i, j;
    for (i = 0; i < nov; i++)
    {
        for (j = 0; j < nov; j++)
            printf("\t%d", a[i][j]);
        printf("\n");
    }
}

int main()
{
    // int ch;
    creatematrix();
    printf("\n\t***Adjacency Matrix****\n");
    display(a);
    return 0;
}