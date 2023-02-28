#include <stdio.h>

int main()
{
    int n=10,a[n],i,last,key,c=0;
    for(i=0;i<n;i++)
    {    
        a[i]=i+2;
        printf("    %d",a[i]);
    }
    
    printf("\nEnter no to search : ");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(key==a[i])
            printf("\nnot found");
        else
            printf("\nfound at %d",i+1);
        c++;
    }
    if(i==n)
        printf("\nnot found");
    else
        printf("\nfound at %d",i+1);
    printf("\ncount = %d",c);



    printf("\nEnter no sentel : ");
    scanf("%d",&key);
    last=a[n-1];
    a[n-1]=key;
    for(i=0,c=0;a[i]!=key;i++,c++);
    a[n-1]=last;
    if((i<(n-1))||(a[n-1]==key))
        printf("\nfound at %d",i+1);
    else
        printf("\nnot found");
    return 0;
}