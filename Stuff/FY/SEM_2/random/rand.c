#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// int stringlen(char s[100]);
int stringlen(/*char s[100]*/char *pr);


int main(int argc,char *argv[])
{
    char str[100];
    printf("enter string\n");
    gets(str);
    int length=stringlen(str);
    printf("length of string \"%s\" is %d",str,length);

//     FILE *r1, *w1;
//     // r1 = fopen("rand.txt", "r");
//     // w1 = fopen("randw.txt", "w");
//     r1 = fopen(argv[1], "r");
//     w1 = fopen(argv[2], "w");
//     if (r1 == NULL || w1 == NULL)
//     {
//         printf("file not found");
//         exit(0);
//     }

//        char c=fgetc(r1);
//        while(c != EOF)
//        {
//         fputc(c,w1);
//         c=fgetc(r1);
//        }

// printf("%s\t%s\t%s",argv[0],argv[1],argv[2]);
//     //    char s[100];
//     //    fgets(s,100,r1);
//     //    fputs(s,w1);
//     //     puts(s);

//     fclose(r1);
//     fclose(w1);
}
int stringlen(/*char s[100]*/char *pr)
{
    int n=0;
    // for (int i = 0;s[i]!= '\0'; i++)
    // {
    //     n++;
    // }

    for (int i = 0; *pr != '\0'; i++)
    {
        n++;
        pr++;
    }
    return n;
    
}