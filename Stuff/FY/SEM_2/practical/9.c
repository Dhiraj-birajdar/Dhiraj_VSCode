//Q1.-write a program to read a strig and 1 character. check whether given character is present in the given string or not?


#include<stdio.h>
#include<string.h>
void main()
{
    char s[100],c,*p;
    printf("\n\nEnter a string : ");
    gets(s);
    printf("\nEnter a character : ");
    scanf("%c",&c);
    p=strchr(s,c);
    if (p==NULL)
        printf("\ncharacter '%c' is not present in string '%s'\n ",c,s);
    else
        printf("\ncharacter '%c' is present in string '%s'\n ",c,s);
}