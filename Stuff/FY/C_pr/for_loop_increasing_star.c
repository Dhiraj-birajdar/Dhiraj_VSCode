#include <stdio.h>
/* for loop for increasing star pattern ex. if  n=3
                *
                **
                ***                     */
int main()
{
    int n;
    printf("Enter the no:\n");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            //printf("%d",j);
            printf("*");
            
        }
        
        printf("\n");
        
    }
    
    
    return 0;
}