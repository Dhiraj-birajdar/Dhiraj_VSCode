#include <stdio.h>
#include <string.h>
int main()
{
    char s[100],t;
    printf("Enter string\n");
    gets(s);
    int i,j,n=strlen(s);
    printf("Before sort \"%s\"\n",s);
    for ( i = 0; i < n-1; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if (s[i]<s[j])
            {
                t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
        }
    }
    printf("After sort \"%s\"\n",s);
}


