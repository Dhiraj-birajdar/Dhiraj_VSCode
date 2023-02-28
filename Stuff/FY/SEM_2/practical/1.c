//p8-write a c program to find maximum from two integers using pointers
#include <stdio.h>
int main()
{
    int a,b,*pa=&a,*pb=&b;
    printf("Enter 2 Numbers A & B : ");
    scanf("%d%d",pa,pb);
    if (*pa>*pb)
        printf("\n%d is maximum number \n",*pa);
    else
        printf("\n%d is maximum number \n",*pb);
    return 0;
}