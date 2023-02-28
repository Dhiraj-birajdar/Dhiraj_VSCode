//SWAP 2 NUMBERS WITHOUT USING 3rd VARIABLE
#include<stdio.h>
int main()
{
    int a,b;
    printf("ENTER 2 NUMBERS:");
    scanf("%d%d",&a,&b);
    printf("BEFORE SWAP A:%d B:%d \n",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("AFTER SWAP A:%d B:%d",a,b);
    return 0;
}