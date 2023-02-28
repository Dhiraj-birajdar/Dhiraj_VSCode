#include <stdio.h>
#include <string.h>

int main()
{
    // char a[]="Dhiraj BiRAJdar";
    // char *st=strtok(a," ");
    // printf("%s\n",st);
    /*
    printf("%s\n",strupr(a));
    printf("%s\n",strlwr(a));
    char *s=" pune";
    strcat(a,s);
    printf("%s\n",a);
    printf("%s\n",strrev(a));
    printf("%s\n",strset(a,'5'));*/

    char *s="helio";
    char *p=s;
    printf("%c\t%c\n",*(p+3),s[1]);
}