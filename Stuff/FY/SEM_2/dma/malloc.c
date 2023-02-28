#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    p=(int*)malloc(6*sizeof(int));
    free(p);
    return 0;
}