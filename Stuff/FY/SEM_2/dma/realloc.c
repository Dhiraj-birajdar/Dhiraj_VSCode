#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p=(int*)malloc(10*sizeof(int));
for (int i = 1; i <= 10; i++)
{
    p[i-1]=i*7;
    printf("%d\n",p[i-1]);
}

p=realloc(p,15*sizeof(int));
for (int i = 1; i <=15; i++)
{
    p[i-1]=i*7;
    printf("%d\n",p[i-1]);
}

free(p);
    return 0;
}