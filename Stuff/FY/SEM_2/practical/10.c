//p8-write a program to read 2 integers using pointers & perform all arithmatic operations on them
#include <stdio.h>
void main()
{
    int a,b,*pa=&a,*pb=&b;
    printf("Enter 2 integers : ");
    scanf("%d%d",pa,pb);
    printf("\n%d + %d = %d",a,b,a+b);
    printf("\n%d - %d = %d",a,b,a-b);
    printf("\n%d * %d = %d",a,b,a*b);
    printf("\n%d / %d = %.4f",a,b,(float)a/b);
}