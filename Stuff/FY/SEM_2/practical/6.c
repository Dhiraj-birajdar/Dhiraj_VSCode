//p23-write a program to accept a file name and a single character display the count indicating  total number of times character occur in the file
#include <stdio.h>
#include <string.h>
void main()
{
    FILE *fp;
    char fname[50],c,t;
    int i,count=0;
    printf("Enter File name with extension : ");
    gets(fname);
    fp=fopen(fname,"r");
    if (fp == NULL) {
        printf("Could not open file %s",fname);
        return 0;
    }
    printf("\nEnter character : ");
    scanf("%c",&c);
    for (t=fgetc(fp);t!=EOF;t=fgetc(fp))
    {
        if (c==t)
        {
            count++;
        }
    }
    printf("\ncharacter '%c' occured %d times in file '%s'",c,count,fname);
}