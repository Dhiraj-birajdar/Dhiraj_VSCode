#include <stdio.h>

int main()
{
    int n,rem,temp = n,i=0;
    int bi[10];
    printf("Enter positive natural decimal number:\n");
    scanf("%d",&n);

    while (n>0)
    {
        rem = n%2;
        //i   =(i*2)+ rem;
        n=n/2;
        //printf("%d",rem);
        bi[10]=rem;
    }
    
    printf("%d",bi[10]);
    
    return 0;
}