#include <stdio.h>
/* for loop for increasing right side star pattern ex. if  n=3
                  *
                 ** 
                ***                  */
int main()
{
    int n;
    printf("Enter the number:\n");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if((i+j)<= n)
            {
                printf(" ");
                
            }
            else
            {
                printf("*");
                
            }
        }
        printf("\n");
        
        
    }
    
    return 0;
}