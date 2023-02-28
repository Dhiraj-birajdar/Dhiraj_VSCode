#include<stdio.h>
#include<stdlib.h>
void b_sort(int *a,int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
// int main(int argc,char **argv)
int main()
{
    int i,j,c,n=1;
    FILE *fr,*fw;
    fr=fopen("2d.txt","r");
    fw=fopen("sorted.txt","w+");
    // FILE *fr=fopen(argv[1],"r"),*fw=fopen("sorted.txt","w+");
    // fscanf(fr,"%d",&c);
    printf ("file content is");
    for (i =1; i<= 32; i++)
    {
        fscanf(fr,"%d",&c);
        // c= getw(fr);
        printf ("\n%d",c);
    }
    // c=getw(fr);
    // while(c!=EOF)
    // {
    //     n++;
    //     // fscanf(fr,"%d",&c);
    //     printf("%d\n",c);
    //     c=getw(fr);
    // }
    // printf(" %d ",n);

    /*
    for ( i = 0; i < n; i++)
        fscanf(fr,"%d",&a[i]);
    b_sort(a,n);
    for ( i = 0; i < n; i++)
    {
        fprintf(fw,"%.2d  ",a[i]);
        if((i+1)%4==0)
        fprintf(fw,"\n");
    }
*/
    fclose(fr);
    fclose(fw);
    return 0;
}