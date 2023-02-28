// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// int main()
// {
//     // int a=11,*p;
//     // p=(int*)malloc(sizeof(int));
//     // *p=21;
//     // printf("*p = %d\n",*p);
//     // free(p);
//     // p=6422296;
//     // p=6422300;
//     // printf("*p = %d\n",&a);
//     // printf("*p = %d\n",p);
//     // printf("*p = %d\n",*p);
// char s[30];
// char *name=" DHIRAJ BIRAJDAR HI! \non new line\n";
// char *na="hi i a";
// int a=strlen(name),cnt=0,alc=0;
// printf("length is %d\n\n",a);
//     // printf("enter name\n");
//     // gets(s);
//     // printf("\n\n");
//     puts(name);
//     // printf("\nyour name is %s\n",s);
//     while (*name!='\0')
//     {
//         if (*name!=' ' && *name!='\n')
//         {
//             cnt++;
//         }
//         if (isalpha(*name)!=0)
//         {
//             alc++;
//         }
        
//         name++;
//     }
//     printf(" length without spaces is %d\n",cnt);
//     printf(" length of only alphabets is %d\n",alc);
//     return 0;
// }

// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
    
    char a[]="dhiraj ",s[]="birajdar",f='i';
    strcat(a,s);
    
    printf("%s \n",a);
    printf("%s \n",s);
    puts(a);
    toupper(f);
    printf("%c****%c\n",f,toupper(f));
    printf("%c\n",f);
    printf("\n%s\n",strupr(a));
    strupr(a);
    printf("\n%s\n",a); 
    printf("length of a is %d\nlength of s is %d\n",strlen(a),strlen(s));
    printf("%s\n",strrev(a));
    printf("%s\n",a);
    char p[]="abc",q[]="abC";
    printf("p and q = %d\n",strcmp(p,q));
    printf("p and q = %d\n",stricmp(p,q));
    return 0;
}