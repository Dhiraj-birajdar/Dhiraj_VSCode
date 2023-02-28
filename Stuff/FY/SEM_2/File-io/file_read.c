#include <stdio.h>

int main()
{
    FILE *p;
    int n,n1;
    p=fopen("dbms.txt","r"); 
    // fscanf(p,"%d",&n);
    // fscanf(p,"%d",&n1);
    // printf("value in dbms.txt is %d\n",n);
    // printf("value in dbms.txt is %d\n",n1);

      // fgetc();
    char c=fgetc(p);
    while (c!=EOF)
    {
        printf("%c",c);
        c=fgetc(p);
    }
    
    fclose(p);
    return 0;
}