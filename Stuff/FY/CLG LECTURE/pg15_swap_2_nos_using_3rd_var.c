//SWAP 2 NUMBERS USING 3rd VARIABLE
#include<stdio.h>
int main()
{
    int a,b,c;
    printf("ENTER 2 NUMBERS:");
    scanf("%d%d",&a,&b);
    printf("BEFORE SWAP A:%d B:%d \n",a,b);
    c=a;
    a=b;
    b=c;
    printf("AFTER SWAP A:%d B:%d",a,b);
    return 0;
}