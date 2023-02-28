#include <stdio.h>

int main()
{
    FILE *p;
    char n[] = "dhiraj", n1;
    p = fopen("table.txt", "w");
    int i;
    for (i = 1; i <= 10; i++)
    {
        fprintf(p, "%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d\n", 1 * i, 2 * i, 3 * i, 4 * i, 5 * i,6*i,7*i,8*i,9*i,10*i);
    }
fputc('\n',p);
    i=0;
while (i<=25)
{
    char c='A'+i;
    char d='a'+i;
    fputc(c,p);
    fputc(d,p);
    fputc(' ',p);
    i++;
}
fputc('\n',p);
fputc('\n',p);
i=0;
while (i<=127)
{
    // char a='\0'+i;
    fputc(i,p);
    fputc(' ',p);
    i++;
}

    // printf("value in dbms.txt is %d\n",n);
    fclose(p);
    return 0;
}