#include <stdio.h>
int main()
{
    int *n,a=5;
    n=&a;
    (*n)++;
    printf("\ns : %d",*n);
    printf("\ns: %d",(*n)++);
}