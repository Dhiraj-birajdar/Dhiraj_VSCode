#include <stdio.h>
int main()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            printf(" %2.2d ",j * i);
        }
        printf("\n");
    }
}