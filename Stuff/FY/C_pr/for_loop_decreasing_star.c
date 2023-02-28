#include<stdio.h>
/* for loop for decreasing star pattern ex. if  n=3
                ***
                **
                *                  */
int main()
{
    int n=4;
    // printf("Enter the number:\n");
    // scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            // printf("%d",i);
            printf("@");
        }
        printf("\n");
        // goto start;
    }
    // start:

    return 0;
}