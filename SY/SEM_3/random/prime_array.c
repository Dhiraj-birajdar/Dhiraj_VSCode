#include<stdio.h>
#include<stdlib.h>
void prime(int a[],int n)
{
    int i,j,p;
    printf("Prime numbers are :  ");
    for(i=0;i<n;i++)
    {
        p=1;
        if(a[i]<2)
            p=0;
        for(j=2;j<a[i];j++)
        {
            if(a[i]%j==0)
                p=0;
        }
        if(p==1)
            printf("%d  ",a[i]);
    }
}
int main()
{
    int n,*a,i;
    printf("Enter size of array : ");
    scanf("%d",&n);
    a=(int *)calloc(n,sizeof(int));
    printf("\nEnter %d elements : ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    prime(a,n);
    return 0;
}
