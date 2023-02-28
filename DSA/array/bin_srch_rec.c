#include<stdio.h>
int binary_srch(int *a,int l,int r,int f)
{
    int m=(l+r)/2;
    if(a[m]==f)
        return m;
    else if(l>r)
        return -1;
    else if(f>a[m])
        binary_srch(a,m+1,r,f);
    else if(f<a[m])
        binary_srch(a,l,m-1,f);
}
int main()
{
    int i, n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int a[n];
    int l=0,r=n-1,no;
    printf("\nEnter %d elements in ascending order : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter no to find : ");
    scanf("%d",&no);
    i=binary_srch(a,l,r,no);
    i==-1?printf("%d not found",no):printf("%d found at position %d ",no,i+1);
}