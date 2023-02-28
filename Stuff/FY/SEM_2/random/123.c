#include <stdio.h>
void py();
int main()
{
    // int n;
    // printf("Enter no\n");
    // scanf("%d",&n);
    // printf("deximal : %d\thexadecimal : %0X\n",n,n);
    // return 0;
    py();
}

void py()
{
    int det,r,c,mat[4];
    printf("Enter 4 values of 2 * 2 matrix :\n");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d",&mat[i]);
    }
    det=(mat[0]*mat[3])-(mat[1]*mat[2]);
    printf("Determinant is %d\n",det);
}

