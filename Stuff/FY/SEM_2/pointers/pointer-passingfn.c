#include <stdio.h>
void swap(int *x,int *y);
int main()
{
    int a=1,b=2;
    printf("before  a = %d\tb = %d\n",a,b);
    swap(&a,&b);
    printf("after   a = %d\tb = %d\n",a,b);
    return 0;
}

void swap(int *x,int *y)// call by reference
{
    int temp=*x;
    *x = *y;
    *y = temp;
}