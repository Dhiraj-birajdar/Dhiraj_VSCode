// p16-write a program to accept a string and find its length using user defined function (dont use pointer)
#include <stdio.h>
#include <string.h>
int slength(char fs[100]);
void main()
{
    char s[100];
    int l;
    printf("Enter a string : ");
    gets(s);
    l = slength(s);
    printf("\nLength of string \"%s\" is %d", s, l);
}
int slength(char fs[100])
{
    int i, l = 0;
    for (i = 0; fs[i] != NULL; i++)
    {
        l++;
    }
    return l;
}