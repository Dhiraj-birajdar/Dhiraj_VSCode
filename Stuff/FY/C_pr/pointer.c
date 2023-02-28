#include <stdio.h>
int main()
{
    int a=5, *b=&a,**c=&b,***d=&c;

    printf("a=%d\n",a);
    printf("address of a is %u\n",&a);
    printf("address of b is %u\n",&b);
    printf("address of c is %u\n",d);
    printf("value of a is %u\n",**c);
    printf("value of c is %u\n",*&c);   // *- value at   &- address of   c
    
    return 0;
}