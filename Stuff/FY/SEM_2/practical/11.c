#include <stdio.h>
void main()
{
    char f[30];
    int n;
    printf("Enter file name : ");
    scanf("%s",f);
    FILE *fp,*fo,*fe;
    fp=fopen(f,"r");
    fo=fopen("odd.txt","w");
    fe=fopen("even.txt","w");
    if(fp==NULL)
    {
        printf("Unable to open \"%s\" file\n",f);
        exit(0);
    }
    fscanf(fp,"%d",&n);
    while(1)
    {
        if (n%2==0)
            fprintf(fe,"%d\t",n);
        else
            fprintf(fo,"%d\t",n);
        if( feof(fp) )
        break ;
        fscanf(fp,"%d",&n);
    }
    fclose(fp);
    fclose(fe);
    fclose(fo);
    printf("File \"%s\" has been read and even numbers are written in \"even.txt\" and odd numbers are written in \"odd.txt\" file",f);
}