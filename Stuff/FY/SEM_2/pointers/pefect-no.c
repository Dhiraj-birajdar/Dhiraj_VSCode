#include <stdio.h>

int main()
{
    int no, sum = 0,d=0;
    printf("Enter no\n");
    scanf("%d", &no);

for (int s = 1; s <= no; s++)
{
    

    for (int i = 1; i <s; i++)
    {
        if (s%i==0)
        {
            sum+=i;
        }
        
    }
    if (sum==s)
    {
        d+=1;
        printf("%d is perfect no\n",s);
    }
    sum=0;
}
printf("%d",d);
}
