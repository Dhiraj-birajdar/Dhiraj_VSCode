#include <stdio.h>
/* for loop for pyramid star pattern ex. if  n=3
                *
               * *
              * * *                  */
int main()
{
    int n,num=1;
    printf("Enter the no:\n");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        for (int space = 1; space <=(n-i); space++)
        {
            printf(" ");
        }
        for (int j = 1; j <=i; j++)
        {
            printf("* ");
            
        }
        printf("\n");
        
        
    }
    return 0;
}