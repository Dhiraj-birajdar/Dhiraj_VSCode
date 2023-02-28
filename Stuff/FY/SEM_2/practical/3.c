//p14-write a program to read a string and copy it to another string and display copied string. also the length of copied string.
#include <stdio.h>
#include <string.h>
void main()
{
    char s1[100],s2[100];
    int sl;
    printf("Enter 1st string : ");
    gets(s1);
    printf("\nEnter 2nd string : ");
    gets(s2);
    printf("\nBefore copy \nS1 : \"%s\"\nS2 : \"%s\"",s1,s2);
    strcpy(s2,s1);
    printf("\nAfter copy \nS1 : \"%s\"\nS2 : \"%s\"",s1,s2);
    sl=strlen(s2);
    printf("\nLength of copied string S2 is %d\n",sl);
}