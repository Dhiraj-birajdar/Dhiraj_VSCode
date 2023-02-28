#include <stdio.h>

int main()
{
    int n,rem,i=0,j;
    printf("Enter no:\n");
    scanf("%d",&n);
int temp = n;
    while (n>0)
    {
        rem = n % 10;
        i   =(i*10)+ rem;
        n  = n/10;
        // j = i;
    }
     // printf("%d",i);

    if (i==temp)
    {
        printf("%d is palindrome number",temp);        

    }
    else
    {
        printf("%d is not palindrome number",temp);
    }
    
    




    
    return 0;
}