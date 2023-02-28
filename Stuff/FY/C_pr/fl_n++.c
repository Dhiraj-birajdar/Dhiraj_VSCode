#include <stdio.h>
/* for loop for increasing number pattern ex. if  n=3
                1
                2 3
                4 5 6                  */
int main()
{
    int n,num=1;
    printf("Enter the no:\n");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            //printf("%d",j);
            printf("%d ",num++);
            
        }
        
        printf("\n");
        
    }
    
    
    return 0;
}