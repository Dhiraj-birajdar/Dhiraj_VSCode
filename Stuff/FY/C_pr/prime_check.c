#include <stdio.h>

int main()
{
    int n,isprime =1;
    printf("Enter a no: \n");
    scanf("%d",&n);

    for (int i = 2; i < n; i++)
    {
        if (n%i==0)
        {
            isprime =0;
            break;
        }
    }
    
    if (isprime ==0)
        printf("%d is not a prime no\n",n); 
    else
        printf("%d is a prime no\n",n);    
    
    return 0;
}


    // if (isprime ==0)
    // {
    //     printf("%d is not a prime no\n",n); 
    // }
    // else
    // {
    //     printf("%d is a prime no\n",n);    
    // }