#include <stdio.h>
int main()
{
    int a,i=0;
    printf("enter the no:\n");
    scanf("%d",&a);
    // do                           
    // {
    //     printf("%d\n",i+1);
    //     i++;
        
    // } while (i<a);
    for ( i = 0; i < a; i++)
    {
        printf("%d\n",i+1);
        
    }
    return 0;
}