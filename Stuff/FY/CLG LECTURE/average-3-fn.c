#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int average(int a, int b, int c)
{
    return (a + b + c) / 3;
}
int main()
{
    int n1, n2, n3;
    // printf("Enter 3 numbers.\n");
    // scanf("%d%d%d", &n1, &n2, &n3);
    // printf("Average of 3 numbers is %d\n", average(n1, n2, n3));


    char *g="hi! i am string";
    char s[]="dhiraj birajdar";
    // printf("enter\n");
    // gets(s);

    // printf("%s\n",s);
    // // printf("%s\n",g);
    // printf("%c\n",*s);
    // printf("%c\n",*(s+1));
    // printf("%c\n",*(s+2));
    // printf("%c\n",*(s+3));
    // printf("%c\n",*(s+4));
    // printf("%u\n",*(s+5));

    char d[]="hi my name is sam";
    char f[strlen(d)+1],*t=d;
    for (int i = 0; i < (strlen(d)+1); i++)
    {
        f[i]=d[i];
    }
    char *k=malloc(strlen(d)+1);// char k[strlen(d)+1]=malloc(strlen(d)+1);   or  int e=strlen(d)+1;  k[e]=malloc(e);
    strcpy(k,d);

    printf("%s\n",d);
    printf("%s\n",f);
    printf("%p\n",d);
    printf("%p\n",t);
    printf("%p\n",f);
    printf("%s\n",t);

    printf("\n\n%s\n",k);
    printf("%p\n",k);

}