//p8-write a program to accept an integer using pointer & check whether it is even or odd
#include <stdio.h>
void main()
{
    int n,*pn=&n;
    printf("Enter the no : ");
    scanf("%d",pn);
    if (*pn%2==0)
        printf("\n%d is even",*pn);
    else
        printf("\n%d is odd",*pn);
}