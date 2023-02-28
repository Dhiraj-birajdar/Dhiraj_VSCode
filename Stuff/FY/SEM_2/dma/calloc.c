#include <stdio.h>

int main()
{
    int *p,n;
    printf("Enter the no of integers.\n");
    scanf("%d",&n);

    p=(int*)calloc(n,sizeof(int));//  value is 0 by default instead of garbage value
    free(p);
    return 0;
}